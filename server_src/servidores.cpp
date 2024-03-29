#include <vector>
#include "../common_src/thread_tda.h"
#include "../common_src/excepciones.h"
#include "servidores.h"
#include "server_proto.h"
#include "servidor_thread.h"
#include "monitor.h"
#include "vector_server_threads.h"
#define THREADS 1

void Servidores::run(){
	try{
		while (true){
			for (int i = 0; i < THREADS; ++i){
				SrvThread* new_thread = new SrvThread(srvProtocolo, monitor);
				conexiones.agregarThread(new_thread);
				new_thread->start();
			}
			conexiones.revisarThreads();
		}
	} catch (ExceptionSocketAccept &e){
		conexiones.limpiarThreads();
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		conexiones.limpiarThreads();
	}
}
