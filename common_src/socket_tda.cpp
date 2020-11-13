#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <utility>
#include "socket_tda.h"
#include "excepciones.h"
#include "direccion.h"

void Socket::crearSocket(Direccion &dir){
	for (; !dir.estaVacia(); dir.sigDir()){
		fileDesc = socket(dir.getFamily(), dir.getSockType(), dir.getProtocol());
		if (fileDesc != -1){
			return;
		}
	}
}

int Socket::conectarse(Direccion &dir){
	int conectado = -1;
	while (!dir.estaVacia() && conectado == -1){
		dir.sigDir();
		::close(fileDesc);
		fileDesc = -1;
		crearSocket(dir);
		if (!dir.estaVacia()){
			conectado = ::connect(fileDesc, dir.getAddr(), dir.getAddrLen());
		}
	}
	return conectado;
}

Socket::Socket(Direccion &dir){
	int val = 1;
	fileDesc = -1;

	crearSocket(dir);
	if(fileDesc == -1){
		throw ExceptionSocket(__func__);
	}
	setsockopt(fileDesc, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
}

Socket::Socket(int fd){
	fileDesc = fd;
}

Socket::Socket(Socket &&other){
	fileDesc = other.fileDesc;
	other.fileDesc = -1;
}

void Socket::connect(Direccion &dir){
	int conectado;
	conectado = ::connect(fileDesc, dir.getAddr(), dir.getAddrLen());
	if (conectado == -1){
		conectado = conectarse(dir);
	}
	if (conectado == -1){
		throw ExceptionSocket(__func__);
	}
}

void Socket::bind(Direccion &dir){
	if (::bind(fileDesc, dir.getAddr(), dir.getAddrLen()) == -1){
		throw ExceptionSocket(__func__);
	}
}

void Socket::listen(int cantListen){
	if (::listen(fileDesc, cantListen) == -1){
		throw ExceptionSocket(__func__);
	}
}

Socket Socket::accept(Direccion &dir){
	int fd_server = ::accept(fileDesc, dir.getAddr(), &(dir.getAddrLen()));
	if (fd_server == -1){
		throw ExceptionSocketAccept(__func__);
	}
	return std::move(Socket(fd_server));
}

int Socket::send(char* msj, int largo){
	int cant_enviado = 0;

	while(largo > cant_enviado){
		int tam = largo - cant_enviado;
		char* offset = msj + cant_enviado;
		int aux = ::send(fileDesc, offset, tam, MSG_NOSIGNAL);
		cant_enviado += aux;

		if(aux == -1){
			throw ExceptionSocket(__func__);
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
		int aux = ::recv(fileDesc, offset, tam, 0);
		cant_recv += aux;

		if(aux == -1){
			throw ExceptionSocket(__func__);
		}else if (aux == 0){
			break;
		}
	}
	return cant_recv;
}

void Socket::shutdown(int tipo){
	::shutdown(fileDesc, tipo);
}

Socket::~Socket(){
	if (fileDesc != -1){
		::close(fileDesc);
	}
}
