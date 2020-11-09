#include <sys/socket.h>
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "server_proto.h"
#include "servidor_thread.h"

SrvThread::SrvThread(Socket &sk, struct addrinfo* dir, ServidorProt &prot):
servidor(sk.accept(dir)), prototipo(prot){
}

void SrvThread::run(){
	std::string respuesta  = prototipo.recibir(servidor);
	prototipo.enviar(servidor, respuesta);
	is_alive = false;
}

bool SrvThread::is_dead(){
	return !is_alive;
}

void SrvThread::stop(){
	servidor.shutdown(SHUT_RDWR);
}

SrvThread::~SrvThread(){
}
