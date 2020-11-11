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

int ClCorredor::operator()(char* host, char* port){
	try{
		Direccion direccion(host, port, 0);
		Socket socketCl(direccion.get());
		ClienteProt enviadorCliente(socketCl, direccion);
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
