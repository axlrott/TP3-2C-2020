# TP3

## Nombre y Apellido: Axel Aparicio Rotermund
## Padron: 96283
## Link Github: https://github.com/axlrott/TP3-2C-2020.git

### Clases En Comun:

#### Socket:

Esta clase va a representar un socket y va a tener todas sus funciones, en donde sea necesario se va a pedir que se le pase como parametro un puntero a un **struct addrinfo** con el que se creo el socket para utilizarlo, cuando se crea se va a iterar hasta encontrar la direccion en la que sea creado con exito, lo mismo con connect donde se iterara hasta encontrar una direccion en la cual se cree y se conecte con exito.
En caso de que haya algun error en alguna funcion se lanzara la excepcion **ExceptSocket**, menos en ***accept()*** donde se lanzara la excepcion **ExceptSocketAccept**.

#### Direccion:

Esta clase va a ser una representacion de un puntero de **struct addrinfo** el cual se va a crear pasandole el host, el puerto y el flag correspondiente, va a tener una funcion ***get()*** en la cual se devolvera el puntero y el destructor va a tomar el puntero y le va a hacer un ***freeaddrinfo()*** para liberar la memoria.

#### Thread:

Esta clase de Thread esta hecha para ser la clase padre de las que yo quiera que se utilicen los threads, la misma se va a ejecutar utilizando la funcion ***start()*** lo cual va a crear el thread con la funcion ***run()*** de la clase que herede a esta.

### Clases de Cliente:

#### Main:

Esta clase va a tomar el host y el puerto pasado por parametro, va a crear la clase **Client Corredor** y luego va a llamar a este con los parametros, al finalizar se retornara un 0. En caso de que atrape una excepcion del tipo **std::exception** se mostrara por pantalla el mensaje de error y se retornara un 1, en caso de que atrape otro tipo de error se informara que hubo un error desconocido y tambien se retornara 1.

#### Client Corredor:

Esta clase va a recibir un host y un puerto con los que creara una clase **Direccion** y usara esta para crear una clase **Socket** y luego va a utilizar ese **Socket** y esa **Direccion** para crear un **Cliente Protocolo**, el cual luego se llamara como funcion. En caso de que atrape una excepcion del tipo **std::exception** se mostrara por pantalla el mensaje de error y se retornara un 1, en caso de que atrape otro tipo de error se informara que hubo un error desconocido y tambien se retornara 1.

#### Client Protocolo:

Esta funcion va a servir para conectar el socket y enviar el protocolo HTTP a traves de ese socket y luego recibir tambien a traves del socket la respuesta al protocolo enviado e imprimirla por pantalla, privadamente va a estar separada en funciones ***conectar()***, ***recibir()*** y ***enviar()***, y publicamente solo se podra usar esta clase como funcion, lo cual va a llamar a esas 3 funciones en el orden adecuado.

### Clases de Servidor:

#### Main

Esta clase va a tomar el puerto y el nombre del archivo pasados por parametro, va a crear la clase **Server Corredor** y la va a llamar con el puerto y el nombre del archivo, al finalizar esto se retornara un 0. En caso de que atrape una excepcion del tipo **std::exception** se mostrara por pantalla el mensaje de error y se retornara un 1, en caso de que atrape otro tipo de error se informara que hubo un error desconocido y tambien se retornara 1.

#### Server Corredor:

Esta clase va a crear una **Direccion**, luego un **Socket** con esa **Direccion**, luego un **Server Protocolo** con la **Direccion**, el **Socket** y el nombre del archivo pasado por parametro, va a llamar a la funcion para inicializar ese **Server Protocolo** y luego va a crear dos threads: **EsperarExit** y **Servidores**, a este ultimo le pasara el **Server Protocolo** como parametro, luego se hara un ***start()*** de ambos threads, se hara un ***join()*** de EsperarExit y cuando este finalice se hara un ***shutdown()*** de el **Socket** y luego se procedera a hacer un ***join()*** de **Servidores**, luego se eliminaran **EsperarExit** y **Servidores** para liberar memoria, al finalizar se retornara 0, en caso de algun error se retornara el mensaje de error correspondiente y se retornara un 1;

#### Lector Protocolo:

#### Diccionario Protocolo

#### Server Protocolo:

#### Esperar Exit:

#### Servidores:

#### Monitor:

#### Servidores Threads:

#### Vector de Servidores Threads:

### Excepciones:

### Diagrama:

![Diagrama](imgs/Diagrama.png)
