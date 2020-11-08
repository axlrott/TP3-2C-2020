#ifndef PROCESADOR_PROTOCOLO
#define PROCESADOR_PROTOCOLO

#include <map>

class ProcesadorProto{
private:
	std::map<std::string, std::string> recursos;
	std::string hacerGet(std::string recurso);
	std::string hacerPost(std::string recurso, std::string msj);
public:
	explicit ProcesadorProto(const char* nombre_archv);
	std::string operator()(std::string protocolo);
	~ProcesadorProto();
	
};

#endif