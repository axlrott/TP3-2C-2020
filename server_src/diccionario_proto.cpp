#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "diccionario_proto.h"
#include "lector_protocolo.h"
#define POST "POST"
#define GET "GET"
#define OK " 200 OK\n\n"
#define OK_INDEX " 200 OK\nContent-Type: text/html\n\n"
#define NOT_FOUND " 404 NOT FOUND\n\n"
#define FORBIDDEN " 403 FORBIDDEN\n\n"
#define NOT_ALLOWED " 405 METHOD NOT ALLOWED\n\n"
#define DESCONOCIDO " es un comando desconocido\n"

std::string DiccProto::get(const std::string &recurso){
	if (recursos.count(recurso) == 0){
		return (html + NOT_FOUND);
	}
	if (recurso == "/"){
		return (html + OK_INDEX + recursos[recurso]);
	}
	return (html + OK + recursos[recurso]);
}

std::string DiccProto::post(const std::string &rec, const std::string &msj){
	if (rec == "/"){
		return (html + FORBIDDEN);
	}
	recursos[rec] = msj;
	return (html + OK + msj);
}

DiccProto::DiccProto(char* nombre_archv){
	std::string msjIndex;
	std::ifstream archv;
	archv.open(nombre_archv);
	std::getline(archv, msjIndex, '\0');
	recursos["/"] = msjIndex;
}

std::string DiccProto::operator()(const std::string &protocolo){
	LectorProtocolo lector(protocolo);
	std::cout << lector.getPrimerLinea() << std::endl;
	html = lector.getProtocolo();
	if (lector.getMetodo() == GET){
		return get(lector.getRecurso());
	} else if (lector.getMetodo() == POST){
		return post(lector.getRecurso(), lector.getMensaje());
	} else {
		std::string res = html + NOT_ALLOWED + lector.getMetodo() + DESCONOCIDO;
		return res;
	}
}
