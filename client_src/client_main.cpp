#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "../common_src/socket_tda.h"
#include "../common_src/crear_dir.h"
#include "../common_src/excepciones.h"
#include "client_proto.h"

int main(int argc, char const *argv[]){
	CrearDir crearDir;
	ClienteProt enviador;
	char* host = (char*) argv[1];
	char* port = (char*) argv[2];
	struct addrinfo* dir = crearDir(host, port, 0);
	try{
		Socket sock(dir);
		enviador.enviar(sock, dir);
		enviador.recibir(sock, dir);
		freeaddrinfo(dir);
	} catch(ExceptionSocket& e){
		std::cout << e.what() << std::endl;
		freeaddrinfo(dir);
		return 1;
	}
	return 0;
}
