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

struct addrinfo* Direccion::get(){
	return dir;
}

Direccion::~Direccion(){
 freeaddrinfo(dir);
}

