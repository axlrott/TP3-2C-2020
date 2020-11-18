#include <mutex>
#include <string>
#include "monitor.h"
#include "server_proto.h"
#include "../common_src/socket_tda.h"

std::string Monitor::respuestaProtocolo(std::string protocolo){
	std::unique_lock<std::mutex> lck(m);
	return dProtocolo(protocolo);
}
