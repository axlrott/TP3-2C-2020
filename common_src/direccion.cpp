#include "excepciones.h"
#include <netdb.h>
#include <string.h>
#include "direccion.h"

Direccion::Direccion(const char* host, const char* port, int flag){
	bool exito;
	struct addrinfo dir_host;
	memset(&dir_host, 0, sizeof(struct addrinfo));
	dir_host.ai_family = AF_INET;
	dir_host.ai_socktype = SOCK_STREAM;
	dir_host.ai_flags = flag;

	exito = getaddrinfo(host, port, &dir_host, &dir) == 0;
	if (!exito){
		throw ExceptionDireccion(__func__);
	}
}

void Direccion::sigDir(){
	dir = dir->ai_next;
}

int Direccion::getFamily(){
	return dir->ai_family;
}

int Direccion::getSockType(){
	return dir->ai_socktype;
}

int Direccion::getProtocol(){
	return dir->ai_protocol;
}

struct sockaddr* Direccion::getAddr(){
	return dir->ai_addr;
}

socklen_t& Direccion::getAddrLen(){
	return dir->ai_addrlen;
}

bool Direccion::estaVacia(){
	return (dir == NULL);
}

Direccion::~Direccion(){
 freeaddrinfo(dir);
}

