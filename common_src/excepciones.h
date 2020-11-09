#ifndef EXCEPCIONES
#define EXCEPCIONES

#include <iostream>

class ExceptionSocket : public std::exception{
protected:
	int numero;
	std::string msj;
public:
	virtual const char* what() const throw(){
		return msj.c_str();
	}
};

class ExceptionSocketCreate : public ExceptionSocket{
public:
	ExceptionSocketCreate(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketConnect : public ExceptionSocket{
public:
	ExceptionSocketConnect(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketBind : public ExceptionSocket{
public:
	ExceptionSocketBind(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketListen : public ExceptionSocket{
public:
	ExceptionSocketListen(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketAccept : public ExceptionSocket{
public:
	ExceptionSocketAccept(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketSend : public ExceptionSocket{
public:
	ExceptionSocketSend(std::string error_msj){
		msj = error_msj;
	}
};

class ExceptionSocketRecive : public ExceptionSocket{
public:
	ExceptionSocketRecive(std::string error_msj){
		msj = error_msj;
	}
};

#endif