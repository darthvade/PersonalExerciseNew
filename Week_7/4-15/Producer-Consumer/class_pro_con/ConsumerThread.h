#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include <pthread.h>
#include "WorkingQueue.h"
#include <iostream>
#include <unistd.h>
#include "Mutex.h"

class ConsumerThread {
	public:
		ConsumerThread(WorkingQueue *wq, int frequent, Mutex *cout_lock);
		~ConsumerThread();
		void start();
		void join();
	private:
		pthread_t _p_id;
		WorkingQueue *_wq;
		int _frequent;
		Mutex *_cout_lock;
		static void* _consumer_action(void *args);
		void _run();
};

#endif
