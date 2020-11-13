#ifndef DICCIONARIO_PROTOCOLO
#define DICCIONARIO_PROTOCOLO

#include <map>
#include <string>

/*DiccProto va a guardar en un diccionario los recursos como clave y los
mensajes como valor. Se construye a partir de un archivo que representa el
recurso indice, o "/", y cuando se lo llama con el operador () pasandole un
string, que deberia respetar el protocolo HTTP, luego revisa si es de tipo
GET o POST y actua en base a ello y devuelve la respuesta correspondiente*/
class DiccProto{
private:
	std::map<std::string, std::string> recursos;
	std::string html;
	std::string get(const std::string &recurso);
	std::string post(const std::string &recurso, const std::string &msj);
public:
	explicit DiccProto(const char* nombre_archv);
	std::string operator()(const std::string &protocolo);
	~DiccProto() {}
};

#endif
