#ifndef EXCEPCIONES
#define EXCEPCIONES

#include <iostream>
#include <exception>
#include <string>

/*Exceptiones utilizadas en el programa, se diferencia
la clase ExceptionSocket de la ExceptionSocketAccept para
poder hacerle un catch en la clase Servidores*/
class ExceptionSocket : public std::exception{
protected:
	char clase[7] = "SOCKET";
	std::string msj_error;
public:
	ExceptionSocket() {}
	explicit ExceptionSocket(const char* funcion);
	virtual const char* what() const noexcept;
	virtual ~ExceptionSocket() noexcept {}
};

class ExceptionSocketAccept : public ExceptionSocket{
public:
	explicit ExceptionSocketAccept(const char* funcion);
	virtual ~ExceptionSocketAccept() noexcept {}
};

class ExceptionDireccion : public std::exception{
protected:
	char clase[10] = "DIRECCION";
	std::string msj_error;
public:
	explicit ExceptionDireccion(const char* funcion);
	virtual const char* what() const noexcept;
	virtual ~ExceptionDireccion() noexcept {}
};

#endif
