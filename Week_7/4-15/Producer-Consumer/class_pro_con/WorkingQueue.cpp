#include "WorkingQueue.h"

WorkingQueue::WorkingQueue(): _condvar(&_mutex) {

}

WorkingQueue::~WorkingQueue() {

}

int WorkingQueue::consume() {
	_mutex.lock();
	while(_Q.empty()) {
		_condvar.wait();	
	}
	int rent = _Q.front();
	_Q.pop();
	_mutex.unlock();
	return rent;
}

void WorkingQueue::product(int n) {
	_mutex.lock();
	_Q.push(n);
	_condvar.notify();
	_mutex.unlock();
}
