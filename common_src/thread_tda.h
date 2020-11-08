#ifndef THREAD_T
#define THREAD_T

#include <thread>

/*Clase Thread basada en una vista en los
ejemplos interactivos de la materia, va a
ser utilizada para hacer Threads por herencia*/
class Thread{
private:
	std::thread thread;
public:
	Thread();
	void start();
	void join();
	virtual void run() = 0; 
	virtual ~Thread() {}
	Thread(const Thread&) = delete;
	Thread& operator=(const Thread&) = delete;
	Thread(Thread&& other);
	Thread& operator=(Thread&& other);
};

#endif
