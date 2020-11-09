#include "esperar_exit.h"

EsperarExit::EsperarExit(){
}

void EsperarExit::run(){
	int caracter;
	do {
		caracter=getchar();
	} while (caracter != 'q');
}

EsperarExit::~EsperarExit(){
}