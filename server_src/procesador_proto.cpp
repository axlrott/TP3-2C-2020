#include <iostream>
#include <fstream>
#include <algorithm>
#include "procesador_proto.h"
#include "lector_protocolo.h"
#define POST "POST"
#define GET "GET"
#define OK "​HTTP 200 OK\n\n"
#define OK_INDEX "​HTTP 200 OK\nContent-Type: text/html\n\n"
#define NOT_FOUND "HTTP 404 NOT FOUND\n\n"
#define FORBIDDEN "HTTP 403 FORBIDDEN\n\n"
#define NOT_ALLOWED "HTTP 405 METHOD NOT ALLOWED\n\n"

std::string ProcesadorProto::hacerGet(std::string recurso){
	if (recursos.count(recurso) == 0){
		return NOT_FOUND;
	}
	std::string retorno;
	if (recurso == "/"){
		retorno += OK_INDEX;
	} else {
		retorno += OK;
	}
	retorno += recursos[recurso];

	return retorno;
}

std::string ProcesadorProto::hacerPost(std::string recurso, std::string msj){
	if (recurso == "/"){
		return FORBIDDEN;
	}
	std::string retorno;
	recursos[recurso] = msj;
	retorno += OK;
	retorno += msj;

	return retorno;
}

ProcesadorProto::ProcesadorProto(const char* nombre_archv){
	std::string msjIndex;
	std::ifstream archv;
	archv.open(nombre_archv);
	std::getline(archv, msjIndex, '\0');
	recursos["/"] = msjIndex;
	archv.close();
}

void imprimirLinea(std::string cadena){
	std::string::iterator comienzo = cadena.begin();
	std::string::iterator final = cadena.end();
	std::string::iterator fin = std::find(comienzo, final, '\n');
	std::string primer_linea(cadena.begin(), fin);
	std::cout << primer_linea << std::endl;
}

std::string ProcesadorProto::operator()(std::string protocolo){
	imprimirLinea(protocolo);
	LectorProtocolo lector(protocolo);
	if (lector.getMetodo() == GET){
		return hacerGet(lector.getRecurso());
	} else if (lector.getMetodo() == POST){
		return hacerPost(lector.getRecurso(), lector.getMensaje());
	} else {
		return NOT_ALLOWED;
	}
}

ProcesadorProto::~ProcesadorProto(){

}
