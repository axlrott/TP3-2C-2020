#ifndef SOCKET_T
#define SOCKET_T

#include <iostream>
#include "direccion.h"

/*Clase que representa un Socket y todas sus funciones, al crear
un socket y hacer connect, se va a iterar la addrinfo pasada hasta
encontrar una con la que pueda conectarse, en caso de error se hara
un throw de ExceptionSocket, excepto en accept que lanzara su propia
excepcion del tipo ExceptSocketAccept*/
class Socket{
private:
	int fileDesc;
	explicit Socket(int fd);
	void crearSocket(Direccion &dir);
	int conectarse(Direccion &dir);
public:
	explicit Socket(Direccion &dir);
	Socket(Socket &&sock);
	Socket(const Socket& copy) = delete;
	Socket operator=(const Socket &copy) = delete;
	void connect(Direccion &dir);
	void bind(Direccion &dir);
	void listen(int cantListen);
	Socket accept(Direccion &dir);
	int send(char* msj, int largo);
	int recv(char* msj, int largo);
	void shutdown(int tipo);
	~Socket();
};

#endif
