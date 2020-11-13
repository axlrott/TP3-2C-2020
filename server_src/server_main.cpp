#include <iostream>
#include "server_corredor.h"

int main(int argc, char const *argv[]){
	try{
		SrvCorredor correrServer;
		return correrServer(argv[1], argv[2]);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	} catch(...){
		std::cout << "Error desconocido" << std::endl;
		return 1;
	}
	return 0;
}
