#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "socket_tda.h"

void Socket::crearSocket(struct addrinfo* dir){
	for (; dir != NULL && fileDescriptor == -1; dir = dir->ai_next){
		fileDescriptor = socket(dir->ai_family, dir->ai_socktype, dir->ai_protocol);
	}
}

int Socket::conectarse(struct addrinfo* dir){
	int conectado = -1;
	while (dir != NULL && conectado == -1){
		dir = dir->ai_next;
		::close(fileDescriptor);
		fileDescriptor = -1;
		crearSocket(dir);
		if (dir != NULL){
			conectado = ::connect(fileDescriptor, dir->ai_addr, dir->ai_addrlen);
		}
	}
	return conectado;
}

Socket::Socket(struct addrinfo* dir){
	int val = 1;
	fileDescriptor = -1;

	crearSocket(dir);
	if(fileDescriptor == -1){
		throw std::exception();
	}
	setsockopt(fileDescriptor, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
}

Socket::Socket(int fd){
	fileDescriptor = fd;
}

Socket::Socket(Socket &&other){
	fileDescriptor = other.fileDescriptor;
	other.fileDescriptor = -1;
}

void Socket::connect(struct addrinfo* dir){
	int conectado;
	conectado = ::connect(fileDescriptor, dir->ai_addr, dir->ai_addrlen);
	if (conectado == -1){
		conectado = conectarse(dir);
	}
	if (conectado == -1){
		throw std::exception();
	}
}

void Socket::bind(struct addrinfo* dir){
	if (::bind(fileDescriptor, dir->ai_addr, dir->ai_addrlen) == -1){
		throw std::exception();
	}
}

void Socket::listen(int cantListen){
	if (::listen(fileDescriptor, cantListen) == -1){
		throw std::exception();
	}
}

Socket Socket::accept(struct addrinfo* dir){
	int fd_server = ::accept(fileDescriptor, dir->ai_addr, &(dir->ai_addrlen));
	if (fd_server == -1){
		throw std::exception();
	}
	return std::move(Socket(fd_server));
}

int Socket::send(char* msj, int largo){
	int cant_enviado = 0;

	while(largo > cant_enviado){
		int tam = largo - cant_enviado;
		char* offset = msj + cant_enviado;
		int aux = ::send(fileDescriptor, offset, tam, MSG_NOSIGNAL);
		cant_enviado += aux;

		if(aux == -1){
			throw std::exception();
		}else if (aux == 0){
			break;
		}
	}
	return cant_enviado;
}

int Socket::recv(char* msj, int largo){
	int cant_recv = 0;

	while(largo > cant_recv){
		int tam = largo - cant_recv;
		char* offset = msj + cant_recv;
		int aux = ::recv(fileDescriptor, offset, tam, 0);
		cant_recv += aux;

		if(aux == -1){
			throw std::exception();
		}else if (aux == 0){
			break;
		}
	}
	return cant_recv;
}

void Socket::shutdown(int tipo){
	::shutdown(fileDescriptor, tipo);
}

void Socket::close(){
	::close(fileDescriptor);
}

Socket::~Socket(){
	if (fileDescriptor != -1){
		::close(fileDescriptor);
	}
}
