#ifndef MONITOR
#define MONITOR

#include <mutex>
#include <string>
#include "server_proto.h"
#include "diccionario_proto.h"

/*Monitor para la clase SrvProt, el cual hace el recibir y el enviar de
esta clase con mutex para poder garantizar que en estas funciones no haya
una race condition*/
class Monitor{
private:
	DiccProto dProtocolo;
	std::mutex m;
public:
	explicit Monitor(const char* index): dProtocolo(index) {}
	std::string respuestaProtocolo(std::string protocolo);
	~Monitor() {}
};

#endif
