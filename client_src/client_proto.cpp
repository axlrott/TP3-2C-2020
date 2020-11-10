#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include "../common_src/socket_tda.h"
#include "client_proto.h"
#define LONGBUF 64

void ClienteProt::connect(){
	socket.connect(direccion);
	flag = FLAG_CONECT;
}

void ClienteProt::enviar(){
	if (flag != FLAG_CONECT){
		throw std::exception();
	}
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

void ClienteProt::recibir(){
	if (flag != FLAG_CONECT){
		throw std::exception();
	}
	bool continuar = true;
	std::string respuesta;
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
