#ifndef SERVIDOR_THREAD
#define SERVIDOR_THREAD

#include "../common_src/thread_tda.h"
#include "../common_src/socket_tda.h"
#include "monitor.h"

class SrvThread : public Thread {
private:
	Socket srv;
	Monitor &monitor;
	bool is_alive = true;
public:
	SrvThread(ServidorProt &prt, Monitor &mtr): srv(prt.accept()), monitor(mtr) {}
	virtual void run() override;
	void stop();
	bool is_dead();
	~SrvThread() {}
};

#endif
