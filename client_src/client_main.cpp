#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <fstream>
#include <sstream>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "../common_src/socket_tda.h"
#include "../common_src/crear_dir.h"
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
	} catch(...){
		freeaddrinfo(dir);
		return 1;
	}
	return 0;
}
