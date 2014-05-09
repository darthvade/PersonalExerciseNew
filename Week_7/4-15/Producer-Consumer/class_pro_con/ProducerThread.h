#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include <pthread.h>
#include <iostream>
#include "WorkingQueue.h"
#include <unistd.h>
#include <cstdlib>
#include "Mutex.h"

class ProducerThread {
	public:
		ProducerThread(WorkingQueue *wq, int frequent, Mutex *cout_lock);
		~ProducerThread();
		void start();
		void join();
	private:
		pthread_t _p_id;
		WorkingQueue *_wq;
		int _frequent;
		Mutex *_cout_lock;
		static void* _producer_action(void *args);
		void _run();
};

#endif
