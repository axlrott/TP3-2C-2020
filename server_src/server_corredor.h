#ifndef SERVER_CORREDOR
#define SERVER_CORREDOR

/*SrvCorredor es una funcion que sirve para incializar Direccion,
Socket y SrvProt y luego correr los Threads EsperarExit y Servidores
cuando EsperarExit finalice se hara el shutdown del Socket y luego de
que termine de ejecutarse Servidores se eliminaran ambos Threads*/
class SrvCorredor {
public:
	SrvCorredor() {}
	int operator()(const char* port, const char* index) const;
	~SrvCorredor() {}
};

#endif
