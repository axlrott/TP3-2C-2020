#include <iostream>
#include <sstream>
#include <string.h>
#include <sys/socket.h>
#include "server_proto.h"
#define LONGBUF 64

ServidorProt::ServidorProt(const char* archv): procesador(archv){
}

void ServidorProt::initSocket(Socket &sock, struct addrinfo* dir, int listen){
	sock.bind(dir);
	sock.listen(listen);
}

std::string ServidorProt::recibir(Socket &server){
	bool continuar = true;
	std::string protocolo;
	std::string aux;
	char buffer[LONGBUF+1];
	memset(buffer, '\0', LONGBUF+1);

	while (continuar){
		int cant = server.recv(buffer, LONGBUF);
		protocolo.append(buffer);
		memset(buffer, '\0', LONGBUF+1);
		continuar = (cant == LONGBUF);
	}
	std::string respuesta = procesador(protocolo);
	return respuesta;
}

void ServidorProt::enviar(Socket &server,std::string respuesta){
	std::stringstream stream;
	stream << respuesta;
	stream.seekp(0);
	char msj[LONGBUF];
	int largo = LONGBUF;
	memset(msj, '\0', LONGBUF);

	while (largo == LONGBUF){
		largo = stream.readsome(msj, LONGBUF);
		server.send(msj, largo);
		memset(msj, '\0', LONGBUF);
	}
	server.shutdown(SHUT_WR);
}

ServidorProt::~ServidorProt(){

}
