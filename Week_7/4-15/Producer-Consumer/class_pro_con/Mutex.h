#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>

class CondVar;

class Mutex {
		friend class CondVar;
	public:
		//friend class CondVar;
		Mutex();
		~Mutex();
		void lock();
		void unlock();
	private:
		pthread_mutex_t mutex;
};

#endif
