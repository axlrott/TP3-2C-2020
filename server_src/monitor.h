#ifndef MONITOR
#define MONITOR

#include <mutex>
#include <string>
#include "../common_src/thread_tda.h"
#include "server_proto.h"

class Monitor{
private:
	ServidorProt &prototipo;
	std::mutex m;
public:
	explicit Monitor(ServidorProt &prot): prototipo(prot) {}
	std::string recibirProtected(Socket &socket);
	void enviarProtected(Socket &socket, std::string respuesta);
	~Monitor() {}
};

#endif
