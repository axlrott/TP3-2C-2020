#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "client_corredor.h"
#include "client_proto.h"
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "../common_src/direccion.h"
#include "../common_src/excepciones.h"

int ClCorredor::operator()(const char* host, const char* port) const{
	try{
		ClienteProt enviadorCliente(host, port);
		enviadorCliente();
		return 0;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	} catch(...){
		std::cout << "Error desconocido" << std::endl;
		return 1;
	}
}
