#include <iostream>
#include <sstream>
#include <string>
#include "lector_protocolo.h"

void LectorProtocolo::setPrimerLinea(std::stringstream &stream){
	std::getline(stream, primer_linea, '\n');
	stream.seekg(0);
}

LectorProtocolo::LectorProtocolo(std::string ingreso){
	std::string post = "POST";
	std::stringstream stream(ingreso);
	setPrimerLinea(stream);

	stream >> metodo;
	stream >> recurso;
	stream >> protocolo;
	stream.seekg(0);

	if (metodo == post){
		std::getline(stream, msj, '\n');
		while (msj.size() > 0){
			std::getline(stream, msj, '\n');
		}
		std::getline(stream, msj, '\0');
	}
}

std::string LectorProtocolo::getPrimerLinea(){
	return primer_linea;
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
