#ifndef LECTOR_PROTOCOLO
#define LECTOR_PROTOCOLO

#include <iostream>

class LectorProtocolo{
private:
	std::string metodo;
	std::string recurso;
	std::string msj;
public:
	explicit LectorProtocolo(std::string msj);
	std::string getMetodo();
	std::string getRecurso();
	std::string getMensaje();
	~LectorProtocolo();
};

#endif
