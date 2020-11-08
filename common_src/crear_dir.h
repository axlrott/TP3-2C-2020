#include <netdb.h>

#ifndef CREAR_DIR
#define CREAR_DIR

class CrearDir{
public:
	struct addrinfo* operator()(char* host, char* port, int flag);
};

#endif
