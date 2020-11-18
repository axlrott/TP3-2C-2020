#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "server_corredor.h"
#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "../common_src/direccion.h"
#include "../common_src/excepciones.h"
#include "server_proto.h"
#include "esperar_exit.h"
#include "servidores.h"
#include "monitor.h"
#define CANT_LISTEN 15

int SrvCorredor::operator()(const char* port, const char* index) const{
	try{
		Monitor monitor(index);
		SrvProt servidorProt(port, CANT_LISTEN);

		Thread* esperarSalida = new EsperarExit();
		Thread* threadServidor = new Servidores(servidorProt, monitor);

		esperarSalida->start();
		threadServidor->start();

		esperarSalida->join();
		servidorProt.shutdown();
		threadServidor->join();

		delete esperarSalida;
		delete threadServidor;

		return 0;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	} catch(...){
		std::cout << "Error desconocido" << std::endl;
		return 1;
	}
}
