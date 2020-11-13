#include "excepciones.h"
#include <errno.h>
#include <cstdarg>
#include <cstring>

std::string msjError(const std::string &clase, const char* func, char* tipo){
	std::string retorno;
	std::string funcion = func;
	std::string error = tipo;
	
	retorno = "ERROR de " + clase + " en funcion: " + funcion + "()\n";
	retorno += "Tipo de error: " + error;
	return retorno;
}

ExceptionSocket::ExceptionSocket(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);

	msj_error = msjError(clase, funcion, cErrno);
}

const char* ExceptionSocket::what() const noexcept{
	return msj_error.c_str();
}

ExceptionSocketAccept::ExceptionSocketAccept(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);

	msj_error = msjError(clase, funcion, cErrno);
}

ExceptionDireccion::ExceptionDireccion(const char* funcion){
	int _errno = errno;
	char* cErrno = strerror(_errno);

	msj_error = msjError(clase, funcion, cErrno);
}

const char* ExceptionDireccion::what() const noexcept{
	return msj_error.c_str();
}

ExceptionDiccProto::ExceptionDiccProto(const char* funcion){
	char error[] = "Archivo no encontrado";

	msj_error = msjError(clase, funcion, error);
}

const char* ExceptionDiccProto::what() const noexcept{
	return msj_error.c_str();
}



