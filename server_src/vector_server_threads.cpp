#include <vector>
#include "servidor_thread.h"
#include "vector_server_threads.h"

void VectorSrvTh::agregarThread(SrvThread* srvThread){
	conexiones.push_back(srvThread);
}

void VectorSrvTh::revisarThreads(){
	std::vector<SrvThread*> nuevo_vector;
	for (SrvThread* &conexion : conexiones){
		if (conexion->is_dead()){
			conexion->stop();
			conexion->join();
			delete conexion;
		}else{
			nuevo_vector.push_back(conexion);
		}
	}
	conexiones.swap(nuevo_vector);
}

void VectorSrvTh::limpiarThreads(){
	for (SrvThread* conexion : conexiones){
		conexion->stop();
		conexion->join();
		delete conexion;
	}
}
