#include "excepciones.h"
#include <errno.h>
#include <cstdarg>
#include <cstring>

std::string crearMsjError(char* clase, char* funcion, char* tipo){
	std::string retorno, _clase, _funcion, _tipo;
	_clase = clase;
	_funcion = funcion;
	_tipo = tipo;
	retorno = "ERROR de " + _clase + " en funcion: " + funcion + "()\n";
	retorno += "Tipo de error: " + _tipo;
	return retorno;
}

ExceptionSocket::ExceptionSocket(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);
	msj_error = crearMsjError(clase, (char*) funcion, cErrno);
}

const char* ExceptionSocket::what() const noexcept{
	return msj_error.c_str();
}

ExceptionSocketAccept::ExceptionSocketAccept(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);
	msj_error = crearMsjError(clase, (char*) funcion, cErrno);
}

ExceptionDireccion::ExceptionDireccion(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);
	msj_error = crearMsjError(clase, (char*) funcion, cErrno);
}

const char* ExceptionDireccion::what() const noexcept{
	return msj_error.c_str();
}

