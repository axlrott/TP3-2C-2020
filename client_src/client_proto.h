#ifndef CLIENTE_PROTOTIPO
#define CLIENTE_PROTOTIPO

#include <iostream>
#include "../common_src/socket_tda.h"
#include "../common_src/direccion.h"

/*Esta clase va a contener un socket y una direccion. Al ejecutarse
va a hacer connect del socket, va a enviar lo recibido por entrada
standar de a 64 bytes y cuando finalice va a hacer shutdown de escritura,
luego va a recibir de a 64 bytes y al finalizar va a hacer un shutdown
de lectura y va a imprimir por salida standar lo que recibio*/
class ClienteProt{
private:
	Socket &socket;
	Direccion &direccion;
	void conectar();
	void enviar();
	void recibir();
public:
	ClienteProt(Socket &sk, Direccion &dir): socket(sk), direccion(dir) {}
	void operator()();
	~ClienteProt() {}
};

#endif
