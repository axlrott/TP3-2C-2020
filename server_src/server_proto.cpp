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

Socket SrvProt::accept(){
	return (socket.accept(direccion));
}

std::string SrvProt::recibir(Socket &server){
	bool continuar = true;
	std::string protocolo;
	char buffer[LONGBUF+1];
	memset(buffer, '\0', LONGBUF+1);

	while (continuar){
		int cant = server.recv(buffer, LONGBUF);
		protocolo.append(buffer);
		memset(buffer, '\0', LONGBUF+1);
		continuar = (cant == LONGBUF);
	}
	std::string respuesta = dProto(protocolo);
	return respuesta;
}

void SrvProt::enviar(Socket &server, const std::string &respuesta){
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
