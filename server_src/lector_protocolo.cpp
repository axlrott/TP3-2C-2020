#include <iostream>
#include <sstream>
#include "lector_protocolo.h"

LectorProtocolo::LectorProtocolo(std::string ingreso){
	std::string post = "POST";
	std::stringstream stream(ingreso);

	stream >> metodo;
	stream >> recurso;

	if (metodo == post){
		std::getline(stream, msj, '\n');
		while (msj.size() > 0){
			std::getline(stream, msj, '\n');
		}
		std::getline(stream, msj, '\0');
	}
}

std::string LectorProtocolo::getMetodo(){
	return metodo;
}

std::string LectorProtocolo::getRecurso(){
	return recurso;
}

std::string LectorProtocolo::getMensaje(){
	return msj;
}

LectorProtocolo::~LectorProtocolo(){

}
