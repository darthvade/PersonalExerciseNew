#ifndef __CONDVAR_H__
#define __CONDVAR_H__

#include <pthread.h>
#include "mutex.h"

class CondVar{
	public:
		CondVar(Mutex *mutex);
		~CondVar();
		void wait();
		void notify();
		void notify_all();
	private:
		pthread_cond_t condvar;
		Mutex *mutex;
};


#endif
