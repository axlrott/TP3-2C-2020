#ifndef SERVIDORES
#define SERVIDORES

#include <vector>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"
#include "vector_server_threads.h"

/*Clase que hereda de Threads, esta clase la voy a utilizar para
poder correr los Threads de SrvThread, al aceptar clientes voy a
guardarlos en un vector, al cual le voy a ir liberando la memoria
de los Threads que hayan finalizado su ejecucion cada vez que se
conecte un cliente nuevo, al recibir una Excepcion del Accept voy
a liberar la memoria de todos los Threads del vector y finalizar
la ejecucion*/
class Servidores : public Thread {
private:
	SrvProt &protocolo;
	VectorSrvTh conexiones;
public:
	explicit Servidores(SrvProt &proto): protocolo(proto) {}
	virtual void run() override;
	~Servidores() {}
};

#endif
