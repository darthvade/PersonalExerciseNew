#include "Workthread.h"
#include <iostream>
#include "Threadpool.h"
#include <unistd.h>

using namespace std;

void Workthread::run() {
	while(true) {
		Task task;
		bool ret = _pThreadpool->get_task_queue(task);
		if(ret == false) {
			return;
		}
		compute_task(task._num);
	}
}

void Workthread::register_threadpool(Threadpool *pThreadpool) {
	_pThreadpool = pThreadpool;
}

void Workthread::compute_task(int num) {
	cout << "I'm thread --->" << pthread_self() << endl;
	cout << pthread_self() << " -> strat ! " << endl;
	sleep(5);
	cout << pthread_self() << " -> end ! " << endl;
}
