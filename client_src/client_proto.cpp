#include <iostream>
#include <sstream>
#include <string.h>
#include <sys/socket.h>
#include "../common_src/socket_tda.h"
#include "client_proto.h"
#define LONGBUF 64

ClienteProt::ClienteProt(){
}

void ClienteProt::enviar(Socket &socket, struct addrinfo* dir){
	socket.connect(dir);

	std::stringstream stream;
	stream << std::cin.rdbuf();
	stream.seekp(0);

	char msj[LONGBUF];
	int largo = LONGBUF;
	memset(msj, '\0', LONGBUF);

	while (largo == LONGBUF){
		largo = stream.readsome(msj, LONGBUF);
		socket.send(msj, largo);
		memset(msj, '\0', LONGBUF);
	}
	socket.shutdown(SHUT_WR);
}

void ClienteProt::recibir(Socket &socket, struct addrinfo* dir){
	bool continuar = true;
	std::string respuesta;
	std::string aux;
	char buffer[LONGBUF+1];
	memset(buffer, '\0', LONGBUF+1);

	while (continuar){
		int cant = socket.recv(buffer, LONGBUF);
		respuesta.append(buffer);
		memset(buffer, '\0', LONGBUF+1);
		continuar = (cant == LONGBUF);
	}
	socket.shutdown(SHUT_RD);
	std::cout << respuesta;
}

ClienteProt::~ClienteProt(){
}
