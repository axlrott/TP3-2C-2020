#include "../common_src/thread_tda.h"
#include "esperar_exit.h"

void EsperarExit::run(){
	int caracter;
	do {
		caracter=getchar();
	} while (caracter != 'q');
}
