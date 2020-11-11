#include <netdb.h>
#include <string.h>
#include "direccion.h"

Direccion::Direccion(char* host, char* port, int flag){
	struct addrinfo dir_host;
	memset(&dir_host, 0, sizeof(struct addrinfo));
	dir_host.ai_family = AF_INET;
	dir_host.ai_socktype = SOCK_STREAM;
	dir_host.ai_flags = flag;

	getaddrinfo(host, port, &dir_host, &dir);
}

struct addrinfo* Direccion::get(){
	return dir;
}

Direccion::~Direccion(){
 freeaddrinfo(dir);
}

