#include <vector>
#include "../common_src/thread_tda.h"
#include "../common_src/excepciones.h"
#include "servidores.h"
#include "server_proto.h"
#include "servidor_thread.h"
#include "monitor.h"
#include "vector_server_threads.h"

void Servidores::run(){
	Monitor monitor(prototipo);
	try{
		while (true){
			SrvThread* new_thread = new SrvThread(prototipo, monitor);
			conexiones.agregarThread(new_thread);
			new_thread->start();
			conexiones.revisarThreads();
		}
	} catch (ExceptionSocketAccept& e){
		conexiones.limpiarThreads();
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
		conexiones.limpiarThreads();
		throw;
	}
}
