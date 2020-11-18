#include <sys/socket.h>
#include <string>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"

void SrvThread::run(){
	std::string protocolo  = srvProtocolo.recibir(srv);
	std::string respuesta  = monitor.respuestaProtocolo(protocolo);
	srvProtocolo.enviar(srv, respuesta);
	is_alive = false;
}

bool SrvThread::is_dead() const{
	return !is_alive;
}

void SrvThread::stop(){
	srv.shutdown(SHUT_RDWR);
}
