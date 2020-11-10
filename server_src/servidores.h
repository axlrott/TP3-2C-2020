#ifndef SERVIDORES
#define SERVIDORES

#include <vector>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"
#include "vector_server_threads.h"

class Servidores : public Thread {
private:
	ServidorProt &prototipo;
	VectorSrvTh conexiones;
public:
	explicit Servidores(ServidorProt &prt): prototipo(prt) {}
	virtual void run() override;
	~Servidores() {}
};

#endif
