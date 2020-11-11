#ifndef LECTOR_PROTOCOLO
#define LECTOR_PROTOCOLO

#include <iostream>
#include <string>

/*Al lector protocolo se le pasa un string que respeta el protocolo HTTP
el cual va a parsear para poder guardarse el metodo, el recurso, el 
protocolo, la primer linea, y el mensaje del body si es que el metodo es
POST, a esta clase se le puede pedir cualquiera de esos strings pasados*/
class LectorProtocolo{
private:
	std::string metodo;
	std::string recurso;
	std::string protocolo;
	std::string primer_linea;
	std::string msj;
	void setPrimerLinea(std::stringstream &stream);
public:
	explicit LectorProtocolo(std::string msj);
	std::string getPrimerLinea();
	std::string getMetodo();
	std::string getRecurso();
	std::string getProtocolo();
	std::string getMensaje();
	~LectorProtocolo() {}
};

#endif
