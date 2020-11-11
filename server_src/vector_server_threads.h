#ifndef VECTOR_SERVER_THREADS
#define VECTOR_SERVER_THREADS

#include <vector>
#include "servidor_thread.h"

/*Vector de Srv Threads en el cual se pueden agregar threads
al vector, se puede revisar si alguna conexion ya fue finalizada
y dado el caso liberar la memoria y quitarlo del vector, y limpiar
que elimina todos los datos en el vector liberando su memoria*/
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
