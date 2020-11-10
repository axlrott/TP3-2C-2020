#include <iostream>
#include <sstream>
#include <string>
#include "lector_protocolo.h"

LectorProtocolo::LectorProtocolo(std::string ingreso){
	std::string post = "POST";
	std::stringstream stream(ingreso);

	stream >> metodo;
	stream >> recurso;
	stream >> protocolo;
	std::getline(stream, msj, '\n');

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

std::string LectorProtocolo::getProtocolo(){
	return protocolo;
}

std::string LectorProtocolo::getMensaje(){
	return msj;
}
