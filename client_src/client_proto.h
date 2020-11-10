#ifndef CLIENTE_PROTOTIPO
#define CLIENTE_PROTOTIPO

#include <iostream>
#include "../common_src/socket_tda.h"

enum FLAGS_CPROT{
	FLAG_VACIO, FLAG_CONECT
	};

class ClienteProt{
private:
	Socket &socket;
	struct addrinfo* direccion;
	int flag = FLAG_VACIO;
public:
	ClienteProt(Socket &sk, struct addrinfo* dir): socket(sk), direccion(dir) {}
	void connect();
	void enviar();
	void recibir();
	~ClienteProt() {}
};

#endif
