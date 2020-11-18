#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include "../common_src/socket_tda.h"
#include "client_proto.h"
#define LONGBUF 64

ClienteProt::ClienteProt(const char* host, const char* port):
	direccion(host, port,0), socket(direccion) {}

void ClienteProt::conectar(){
	socket.connect(direccion);
}

void ClienteProt::enviar(){
	std::stringstream stream;
	stream << std::cin.rdbuf();
	stream.seekp(0);

	char msj[LONGBUF+1];
	int largo = LONGBUF;

	while (largo == LONGBUF){
		largo = stream.readsome(msj, LONGBUF);
		socket.send(msj, largo);
	}
	socket.shutdown(SHUT_WR);
}

void ClienteProt::recibir(){
	bool continuar = true;
	char respuesta[LONGBUF+1];
	respuesta[LONGBUF] = '\0';

	while (continuar){
		int cant = socket.recv(respuesta, LONGBUF);
		if (cant < LONGBUF){
			respuesta[cant] = '\0';
		}
		std::cout << respuesta;
		continuar = (cant == LONGBUF);
	}
	socket.shutdown(SHUT_RD);
}

void ClienteProt::operator()(){
	conectar();
	enviar();
	recibir();
}
