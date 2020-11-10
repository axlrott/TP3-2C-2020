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

DiccProto::DiccProto(const char* nombre_archv){
	std::string msjIndex;
	std::ifstream archv;
	archv.open(nombre_archv);
	std::getline(archv, msjIndex, '\0');
	recursos["/"] = msjIndex;
	archv.close();
}

void imprimirLinea(std::string &cadena){
	std::string::iterator comienzo = cadena.begin();
	std::string::iterator final = cadena.end();
	std::string::iterator fin = std::find(comienzo, final, '\n');
	std::string primer_linea(cadena.begin(), fin);
	std::cout << primer_linea << std::endl;
}

std::string DiccProto::operator()(std::string &protocolo){
	imprimirLinea(protocolo);
	LectorProtocolo lector(protocolo);
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
