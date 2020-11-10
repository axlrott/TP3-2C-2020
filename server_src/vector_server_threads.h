#ifndef VECTOR_SERVER_THREADS
#define VECTOR_SERVER_THREADS

#include <vector>
#include "servidor_thread.h"

class VectorSrvTh {
private:
	std::vector<SrvThread*> conexiones;
public:
	VectorSrvTh() {}
	void agregarThread(SrvThread* srvThread);
	void revisarThreads();
	void limpiarThreads();
	~VectorSrvTh() {}
};

#endif
