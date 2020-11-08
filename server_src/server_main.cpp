#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include "../common_src/socket_tda.h"
#include "../common_src/crear_dir.h"
#include "server_proto.h"
#define CANTLISTEN 10

int main(int argc, char const *argv[]){
	CrearDir crearDir;
	char* port = (char*) argv[1];
	struct addrinfo* dir = crearDir(NULL, port, AI_PASSIVE);
	try{
		Socket sock(dir);
		ServidorProt enviador(argv[2]);
		enviador.initSocket(sock, dir, CANTLISTEN);
		Socket server = sock.accept(dir);
		std::string respuesta = enviador.recibir(server);
		enviador.enviar(server, respuesta);
		server.shutdown(SHUT_RDWR);
		sock.shutdown(SHUT_RDWR);
		freeaddrinfo(dir);
	} catch(...){
		freeaddrinfo(dir);
	}

	return 0;
}
