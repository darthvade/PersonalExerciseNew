#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__

#include "Thread.h"
#include <string>

class Threadpool;

class Workthread : public Thread {
public:
	void run();
	void register_threadpool(Threadpool *);
	void compute_task(std::string &solve);
private:
	Threadpool *_pThreadpool;
};

#endif
