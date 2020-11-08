#include <netdb.h>
#include <string.h>
#include "crear_dir.h"

struct addrinfo* CrearDir::operator()(char* host, char* port, int flag){
	struct addrinfo* dir;
	struct addrinfo dir_host;
	memset(&dir_host, 0, sizeof(struct addrinfo));
	dir_host.ai_family = AF_INET;
	dir_host.ai_socktype = SOCK_STREAM;
	dir_host.ai_flags = flag;

	getaddrinfo(host, port, &dir_host, &dir);
	return dir;
}