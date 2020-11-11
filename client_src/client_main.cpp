#include <iostream>
#include "client_corredor.h"

int main(int argc, char const *argv[]){
	ClCorredor correrCliente;
	char* host = (char*) argv[1];
	char* port = (char*) argv[2];
	try{
		int ret = correrCliente(host, port);
		return ret;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	} catch(...){
		std::cout << "Error desconocido" << std::endl;
		return 1;
	}
	return 0;
}
