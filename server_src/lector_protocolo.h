#ifndef LECTOR_PROTOCOLO
#define LECTOR_PROTOCOLO

#include <iostream>
#include <string>

class LectorProtocolo{
private:
	std::string metodo;
	std::string recurso;
	std::string protocolo;
	std::string msj;
public:
	explicit LectorProtocolo(std::string msj);
	std::string getMetodo();
	std::string getRecurso();
	std::string getProtocolo();
	std::string getMensaje();
	~LectorProtocolo() {}
};

#endif
