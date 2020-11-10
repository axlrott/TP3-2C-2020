#include "excepciones.h"
#include <errno.h>
#include <cstdarg>
#include <cstring>

ExceptionSocket::ExceptionSocket(const char* func){
	int _errno = errno;
	char* cErrno = strerror(_errno);
	sErrorno = cErrno;
	funcion = (char*) func;
	msj_error += "Error de socket en funcion: " + funcion + "()\n";
	msj_error += "Tipo de error: " + sErrorno;
}

const char* ExceptionSocket::what() const noexcept{
	return msj_error.c_str();
}

const char* ExceptionSocketAccept::what() const noexcept{
	return msj_error.c_str();
}
