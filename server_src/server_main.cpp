#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "../common_src/socket_tda.h"
#include "../common_src/crear_dir.h"
#include "../common_src/thread_tda.h"
#include "../common_src/excepciones.h"
#include "esperar_exit.h"
#include "servidores.h"
#include "server_proto.h"
#define CANTLISTEN 10

void correrThreads(struct addrinfo* dir, const char* index){
	Socket socketSrv(dir);

	ServidorProt protocolo(socketSrv, dir, index);
	protocolo.inicializar(CANTLISTEN);

	Thread* esperarSalida = new EsperarExit();
	Thread* threadServidor = new Servidores(protocolo);

	esperarSalida->start();
	threadServidor->start();

	esperarSalida->join();
	socketSrv.shutdown(SHUT_RDWR);
	threadServidor->join();

	delete esperarSalida;
	delete threadServidor;
}

int main(int argc, char const *argv[]){
	CrearDir crearDir;
	char* port = (char*) argv[1];
	struct addrinfo* direccion = crearDir(NULL, port, AI_PASSIVE);
	try{
		correrThreads(direccion, argv[2]);
		freeaddrinfo(direccion);
	} catch(ExceptionSocket& e){
		std::cout << e.what() << std::endl;
		freeaddrinfo(direccion);
		return 1;
	} catch(...){
		freeaddrinfo(direccion);
		return 1;
	}
	return 0;
}
