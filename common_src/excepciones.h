#ifndef EXCEPCIONES
#define EXCEPCIONES

#include <iostream>
#include <exception>
#include <string>

class ExceptionSocket : public std::exception{
protected:
	std::string msj_error;
	std::string sErrorno;
	std::string funcion;
public:
	explicit ExceptionSocket(const char* func);
	virtual const char* what() const noexcept;
	virtual ~ExceptionSocket() noexcept {}
};

class ExceptionSocketAccept : public std::exception{
protected:
	std::string msj_error;
public:
	explicit ExceptionSocketAccept(const char* msj): msj_error(msj) {}
	virtual const char* what() const noexcept;
	virtual ~ExceptionSocketAccept() noexcept {}
};

#endif
