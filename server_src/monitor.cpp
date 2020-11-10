#include <mutex>
#include <string>
#include "monitor.h"
#include "server_proto.h"

std::string Monitor::recibirProtected(Socket &socket){
	std::unique_lock<std::mutex> lck(m);
	return prototipo.recibir(socket);
}

void Monitor::enviarProtected(Socket &socket, std::string respuesta){
	std::unique_lock<std::mutex> lck(m);
	prototipo.enviar(socket, respuesta);
}
