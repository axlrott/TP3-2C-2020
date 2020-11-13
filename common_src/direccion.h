#include <netdb.h>

#ifndef DIRECCION
#define DIRECCION

/*Clase Direccion que representa un puntero a un struct addrinfo,
el cual se crea con un host, port y flag, se puede devolver con un
get y al destruirse se liberara la memoria haciendo freeaddrinfo()*/
class Direccion{
private:
	struct addrinfo* dir;
public:
	Direccion(const char* host,const char* port, int flag);
	void sigDir();
	int getFamily();
	int getSockType();
	int getProtocol();
	struct sockaddr* getAddr();
	socklen_t& getAddrLen();
	bool estaVacia();
	~Direccion();
};

#endif
