#ifndef SERVIDOR_PROTOTIPO
#define SERVIDOR_PROTOTIPO

#include <iostream>
#include <string>
#include "../common_src/socket_tda.h"
#include "diccionario_proto.h"

enum FLAGS_PROT{
	FLAG_VACIO, FLAG_INIT
	};

class ServidorProt{
private:
	Socket &socket;
	struct addrinfo* direccion;
	DiccProto dProto;
	int flag = FLAG_VACIO;
public:
	ServidorProt(Socket &sk, void* dir, const char* fl): socket(sk), dProto(fl) {
		direccion = (struct addrinfo*) dir;
	}
	void inicializar(int listen);
	Socket accept();
	std::string recibir(Socket &server);
	void enviar(Socket &server, const std::string &respuesta);
	~ServidorProt() {}
};

#endif
