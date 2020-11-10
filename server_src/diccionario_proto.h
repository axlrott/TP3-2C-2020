#ifndef DICCIONARIO_PROTOCOLO
#define DICCIONARIO_PROTOCOLO

#include <map>
#include <string>

class DiccProto{
private:
	std::map<std::string, std::string> recursos;
	std::string html;
	std::string get(const std::string &recurso);
	std::string post(const std::string &recurso, const std::string &msj);
public:
	explicit DiccProto(const char* nombre_archv);
	std::string operator()(std::string &protocolo);
	~DiccProto() {}
};

#endif
