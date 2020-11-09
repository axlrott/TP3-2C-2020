#ifndef SERVIDOR_THREAD
#define SERVIDOR_THREAD

#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"

class SrvThread : public Thread {
private:
	Socket servidor;
	struct addrinfo* direccion;
	ServidorProt &prototipo;
	bool is_alive = true;
public:
	SrvThread(Socket &sk, struct addrinfo* dir, ServidorProt &prot);
	void run();
	void stop();
	bool is_dead();
	~SrvThread();
};

#endif
