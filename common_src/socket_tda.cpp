#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "socket_tda.h"
#include "excepciones.h"

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
		throw ExceptionSocketCreate("Error al crear Socket");
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
		throw ExceptionSocketCreate("Error al crear Socket");
	}
}

void Socket::bind(struct addrinfo* dir){
	if (::bind(fileDescriptor, dir->ai_addr, dir->ai_addrlen) == -1){
		throw ExceptionSocketBind("Error al hacer bind en Socket");
	}
}

void Socket::listen(int cantListen){
	if (::listen(fileDescriptor, cantListen) == -1){
		throw ExceptionSocketListen("Error al hacer listen en Socket");
	}
}

Socket Socket::accept(struct addrinfo* dir){
	int fd_server = ::accept(fileDescriptor, dir->ai_addr, &(dir->ai_addrlen));
	if (fd_server == -1){
		throw ExceptionSocketAccept("Error al aceptar en el Socket");
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
			throw ExceptionSocketSend("Error al enviar a traves del Socket");
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
			throw ExceptionSocketRecive("Error al Recibir a traves del Socket");
		}else if (aux == 0){
			break;
		}
	}
	return cant_recv;
}

void Socket::shutdown(int tipo){
	::shutdown(fileDescriptor, tipo);
}

Socket::~Socket(){
	if (fileDescriptor != -1){
		::close(fileDescriptor);
	}
}
