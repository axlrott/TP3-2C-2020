#ifndef SERVIDOR_PROTOTIPO
#define SERVIDOR_PROTOTIPO

#include <iostream>
#include <string>
#include "../common_src/socket_tda.h"
#include "../common_src/direccion.h"
#include "diccionario_proto.h"

/*La clase SrvProt la voy a utilizar para almacenar mi socket, la
direccion con la cual va a estar creada el socket y el DiccProto,
la cual la voy a inicializar con el nombre del archivo pasado, la
funcion de esta clase va a ser poder inicializar el socket (haciendo
bind y listen), hacer el accept del socket. Tambien se puede recibir
un protocolo HTTP de otro socket, el cual va a ser agregado al
DiccProto y va a devolver la respuesta correspondiente,y un enviar
que envia el mensaje ingresado a traves del socket*/
class SrvProt{
private:
	Direccion direccion;
	Socket socket;
public:
	SrvProt(const char* port, int listen);
	void inicializar(int listen);
	Socket accept();
	std::string recibir(Socket &server);
	void enviar(Socket &server, const std::string &respuesta);
	void shutdown();
	~SrvProt() {}
};

#endif
