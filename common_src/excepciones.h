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
	std::string msj_error;
	std::string clase = "SOCKET";
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
private:
	std::string msj_error;
	std::string clase = "DIRECCION";
public:
	explicit ExceptionDireccion(const char* funcion);
	virtual const char* what() const noexcept;
	virtual ~ExceptionDireccion() noexcept {}
};

class ExceptionDiccProto : public std::exception{
private:
	std::string msj_error;
	std::string clase = "DICCIONARIO PROTOCOLO";
public:
	explicit ExceptionDiccProto(const char* funcion);
	virtual const char* what() const noexcept;
	virtual ~ExceptionDiccProto() noexcept {}
};

#endif
