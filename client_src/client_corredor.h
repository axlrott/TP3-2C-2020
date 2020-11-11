#ifndef SERVER_CORREDOR
#define SERVER_CORREDOR

/*Esta clase sirve para inicializar la Direccion, el Socket, 
el ClienteProt, y luego va a ejecutar este ultimo*/
class ClCorredor {
private:
public:
	ClCorredor() {}
	int operator()(char* host, char* port);
	~ClCorredor() {}
};

#endif
