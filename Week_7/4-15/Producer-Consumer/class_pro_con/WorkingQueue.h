#ifndef __WORKINGQUEUE_H__
#define __WORKINGQUEUE_H__

#include "Mutex.h"
#include "CondVar.h"
#include <queue>

class WorkingQueue {
	public:
		WorkingQueue();
		~WorkingQueue();
		int consume();
		void product(int n);
	private:
		Mutex _mutex;
		CondVar _condvar;
		std::queue<int> _Q;
};

#endif
