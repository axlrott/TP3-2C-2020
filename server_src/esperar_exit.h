#ifndef ESPERAR_EXIT
#define ESPERAR_EXIT

#include "../common_src/thread_tda.h"

/*Clase que hereda de Thread, la funcion que tiene EsperarExit
es pedir un caracter por entrada estandar y continuar pediendo uno
hasta que se reciba una "q" en ese caso la ejecucion finalizara*/
class EsperarExit : public Thread { 
public:
	EsperarExit() {}
	virtual void run() override;
	~EsperarExit() {}
};

#endif
