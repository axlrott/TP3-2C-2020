#ifndef SOCKET_T
#define SOCKET_T

#include <iostream>

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
