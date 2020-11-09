#ifndef SERVIDORES
#define SERVIDORES

#include <vector>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"

class Servidores : public Thread {
private:
	Socket &socket;
	struct addrinfo* direcciones;
	ServidorProt prototipo;
	std::vector<SrvThread*> conexiones;
	void revisarConexiones();
	void limpiarConexiones();
public:
	Servidores(Socket &sk, struct addrinfo* dir, const char* archv);
	virtual void run() override;
	~Servidores();
};

#endif
