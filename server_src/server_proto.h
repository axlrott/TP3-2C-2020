#ifndef SERVIDOR_PROTOTIPO
#define SERVIDOR_PROTOTIPO

#include <iostream>
#include "../common_src/socket_tda.h"
#include "procesador_proto.h"

class ServidorProt{
private:
	ProcesadorProto procesador;
public:
	explicit ServidorProt(const char* archv);
	void initSocket(Socket &sock, struct addrinfo* dir, int listen);
	std::string recibir(Socket &server);
	void enviar(Socket &server, std::string respuesta);
	~ServidorProt();
};

#endif
