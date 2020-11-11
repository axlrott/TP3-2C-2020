#ifndef SERVIDOR_THREAD
#define SERVIDOR_THREAD

#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "monitor.h"

/*A SrvThread se le pasa un SrvProt y un Monitor, se guarda
el socket que me devuelve el accept del SrvProt y con este se recibe
mediante el monitor una respuesta que luego es enviada mediante el Monitor*/
class SrvThread : public Thread {
private:
	Socket srv;
	Monitor &monitor;
	bool is_alive = true;
public:
	SrvThread(SrvProt &prt, Monitor &mtr): srv(prt.accept()), monitor(mtr) {}
	virtual void run() override;
	void stop();
	bool is_dead();
	~SrvThread() {}
};

#endif
