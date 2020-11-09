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

int main(int argc, char const *argv[]){
	CrearDir crearDir;
	char* port = (char*) argv[1];
	struct addrinfo* dir = crearDir(NULL, port, AI_PASSIVE);
	try{
		Socket sock(dir);

		Thread* esperarSalida = new EsperarExit();
		Thread* threadServidor = new Servidores(sock, dir, argv[2]);

		esperarSalida->start();
		threadServidor->start();

		esperarSalida->join();
		sock.shutdown(SHUT_RDWR);
		threadServidor->join();

		delete esperarSalida;
		delete threadServidor;

		freeaddrinfo(dir);
	} catch(ExceptionSocket& e){
		std::cout << e.what() << std::endl;
		freeaddrinfo(dir);
		return 1;
	} catch(...){
		freeaddrinfo(dir);
		return 1;
	}

	return 0;
}
