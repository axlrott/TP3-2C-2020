#include <vector>
#include <functional>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "../common_src/excepciones.h"
#include "server_proto.h"
#include "servidores.h"
#include "servidor_thread.h"
#define CANTLISTEN 10

Servidores::Servidores(Socket &sk, struct addrinfo* dir, const char* archv):
socket(sk), direcciones(dir), prototipo(archv){
}

void Servidores::revisarConexiones(){
	std::vector<SrvThread*> nuevo_vector;
	for (SrvThread* conexion : conexiones){
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

void Servidores::limpiarConexiones(){
	for (SrvThread* conexion : conexiones){
		conexion->stop();
		conexion->join();
		delete conexion;
	}
}

void Servidores::run(){
	prototipo.initSocket(socket, direcciones, CANTLISTEN);
	try{
		while (true){
			SrvThread* new_thread = new SrvThread(socket, direcciones, prototipo);
			conexiones.push_back(new_thread);
			new_thread->start();
			revisarConexiones();
		}
	} catch (ExceptionSocketAccept& e){
		limpiarConexiones();
	}
}

Servidores::~Servidores(){
}