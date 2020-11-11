#ifndef MONITOR
#define MONITOR

#include <mutex>
#include <string>
#include "../common_src/thread_tda.h"
#include "server_proto.h"

/*Monitor para la clase SrvProt, el cual hace el recibir y el enviar de
esta clase con mutex para poder garantizar que en estas funciones no haya
una race condition*/
class Monitor{
private:
	SrvProt &prototipo;
	std::mutex m;
public:
	explicit Monitor(SrvProt &prot): prototipo(prot) {}
	std::string recibirProtected(Socket &socket);
	void enviarProtected(Socket &socket, std::string respuesta);
	~Monitor() {}
};

#endif
