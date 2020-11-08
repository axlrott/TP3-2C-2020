#ifndef CLIENTE_PROTOTIPO
#define CLIENTE_PROTOTIPO

#include <iostream>
#include "../common_src/socket_tda.h"

class ClienteProt{
public:
	ClienteProt();
	void enviar(Socket &socket, struct addrinfo* dir);
	void recibir(Socket &socket, struct addrinfo* dir);
	~ClienteProt();
};

#endif
