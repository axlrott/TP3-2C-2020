#ifndef ESPERAR_EXIT
#define ESPERAR_EXIT

#include "../common_src/thread_tda.h"

class EsperarExit : public Thread { 
public:
	EsperarExit() {}
	virtual void run() override;
	~EsperarExit() {}
};

#endif
