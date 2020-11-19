#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>
#include "diccionario_proto.h"
#include "lector_protocolo.h"
#include "../common_src/excepciones.h"
#define POST "POST"
#define GET "GET"
#define OK " 200 OK\n\n"
#define OK_INDEX " 200 OK\nContent-Type: text/html\n\n"
#define NOT_FOUND " 404 NOT FOUND\n\n"
#define FORBIDDEN " 403 FORBIDDEN\n\n"
#define NOT_ALLOWED " 405 METHOD NOT ALLOWED\n\n"
#define DESCONOCIDO " es un comando desconocido\n"

std::string DiccProto::get(const std::string &recurso){
	auto tiempo_espera = std::chrono::milliseconds(10);
	std::this_thread::sleep_for(tiempo_espera);
	/*Voy a esperar un tiempo antes de hacer el get y asi evitar
	posibles race condition en caso de que llegue un POST un poco
	antes pero casi al mismo tiempo*/
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
	std::ifstream archv(nombre_archv);

	if(!archv){
		throw ExceptionDiccProto(__func__);
	}
	
	std::getline(archv, msjIndex, '\0');
	recursos["/"] = msjIndex;
}

std::string DiccProto::operator()(const std::string &protocolo){
	LectorProtocolo lector(protocolo);
	std::cout << lector.getPrimerLinea();
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
