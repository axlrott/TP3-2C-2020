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
#define CANT_LISTEN 15

int SrvCorredor::operator()(const char* port, const char* index) const{
	try{
		Direccion direccion(NULL, port, AI_PASSIVE);
		Socket socketSrv(direccion);
		SrvProt protocolo(socketSrv, direccion, index);
		protocolo.inicializar(CANT_LISTEN);

		Thread* esperarSalida = new EsperarExit();
		Thread* threadServidor = new Servidores(protocolo);

		esperarSalida->start();
		threadServidor->start();

		esperarSalida->join();
		socketSrv.shutdown(SHUT_RDWR);
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
