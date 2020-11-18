#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <sstream>
#include <string.h>
#include "server_proto.h"
#define LONGBUF 64

void SrvProt::inicializar(int listen){
	socket.bind(direccion);
	socket.listen(listen);
}

SrvProt::SrvProt(const char* port, int listen):
	direccion(NULL, port, AI_PASSIVE), socket(direccion) {
		inicializar(listen);
}

Socket SrvProt::accept(){
	return (socket.accept(direccion));
}

std::string SrvProt::recibir(Socket &server){
	bool continuar = true;
	std::string protocolo;
	char buffer[LONGBUF+1];
	buffer[LONGBUF] = '\0';

	while (continuar){
		int cant = server.recv(buffer, LONGBUF);
		if (cant < LONGBUF){
			buffer[cant] = '\0';
		}
		protocolo.append(buffer);
		continuar = (cant == LONGBUF);
	}
	return protocolo;
}

void SrvProt::enviar(Socket &server, const std::string &respuesta){
	std::stringstream stream;
	stream << respuesta;
	stream.seekp(0);

	char msj[LONGBUF];
	int largo = LONGBUF;

	while (largo == LONGBUF){
		largo = stream.readsome(msj, LONGBUF);
		server.send(msj, largo);
	}
	server.shutdown(SHUT_WR);
}

void SrvProt::shutdown(){
	socket.shutdown(SHUT_RDWR);
}
