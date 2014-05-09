#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__

#include "Thread.h"

class Threadpool;

class Workthread : public Thread {
public:
	void run();
	void register_threadpool(Threadpool *);
	void compute_task(int num);
private:
	Threadpool *_pThreadpool;
};

#endif
