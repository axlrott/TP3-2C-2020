#ifndef SOCKET_T
#define SOCKET_T

#include <iostream>

/*Clase que representa un Socket y todas sus funciones, al crear
un socket y hacer connect, se va a iterar la addrinfo pasada hasta
encontrar una con la que pueda conectarse, en caso de error se hara
un throw de ExceptionSocket, excepto en accept que lanzara su propia
excepcion del tipo ExceptSocketAccept*/
class Socket{
private:
	int fileDescriptor;
	explicit Socket(int fd);
	void crearSocket(struct addrinfo* dir);
	int conectarse(struct addrinfo* dir);
public:
	explicit Socket(struct addrinfo* dir);
	Socket(Socket &&sock);
	Socket(const Socket& copy) = delete;
	Socket operator=(const Socket &copy) = delete;
	void connect(struct addrinfo* dir);
	void bind(struct addrinfo* dir);
	void listen(int cantListen);
	Socket accept(struct addrinfo* dir);
	int send(char* msj, int largo);
	int recv(char* msj, int largo);
	void shutdown(int tipo);
	~Socket();
};

#endif
