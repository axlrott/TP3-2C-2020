#include <iostream>
#include "server_corredor.h"

int main(int argc, char const *argv[]){
	SrvCorredor correrServer;
	char* port = (char*) argv[1];
	char* index = (char*) argv[2];
	try{
		int ret = correrServer(port, index);
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
