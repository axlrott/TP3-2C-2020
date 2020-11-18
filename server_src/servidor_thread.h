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
	SrvProt &srvProtocolo;
	Monitor &monitor;
	bool is_alive = true;
public:
	explicit SrvThread(SrvProt &svProt, Monitor &mtr):
		srv(svProt.accept()), srvProtocolo(svProt), monitor(mtr) {}
	virtual void run() override;
	void stop();
	bool is_dead() const;
	~SrvThread() {}
};

#endif
