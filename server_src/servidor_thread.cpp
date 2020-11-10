#include <sys/socket.h>
#include <string>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"

void SrvThread::run(){
	std::string respuesta  = monitor.recibirProtected(srv);
	monitor.enviarProtected(srv, respuesta);
	is_alive = false;
}

bool SrvThread::is_dead(){
	return !is_alive;
}

void SrvThread::stop(){
	srv.shutdown(SHUT_RDWR);
}
