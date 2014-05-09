#include "Threadpool.h"

Threadpool::Threadpool(std::vector<Workthread>::size_type max_thread) :
	_task_queue(), _max_thread(max_thread), _thread_vector(_max_thread), _is_started(false), _lock(), _cond(&_lock){
	for(std::vector<Workthread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter) {
		iter->register_threadpool(this);	
	}
}

Threadpool::~Threadpool() {
	stop_threadpool();
}

void Threadpool::start_threadpool() {
	if(_is_started == false) {
		_is_started = true;
		for(std::vector<Workthread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter) {
			iter->start();	
		}
	}
}

void Threadpool::stop_threadpool() {
	if(_is_started == false) {
		return;
	}
	_is_started = false;
	_cond.notifyall();
	for(std::vector<Workthread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter) {
		iter->join();	
	}
	while(!_task_queue.empty()) {
		_task_queue.pop();
	}
}

bool Threadpool::get_task_queue(Task &task) {
	_lock.lock();
	while(_is_started && _task_queue.empty()) {
		_cond.wait();
	}
	if(_is_started == false) {
		_lock.unlock();
		return false;
	}
	task = _task_queue.front();
	_task_queue.pop();
	_lock.unlock();
	return true;
}

bool Threadpool::add_task_queue(Task task) {
	_lock.lock();
	bool ret = false;
	if(_is_started) {
		_task_queue.push(task);
		_cond.notify();
		ret = true;
	}
	_lock.unlock();
	return ret;
}

bool Threadpool::is_task_queue_empty() const {
	_lock.lock();
	bool ret = _task_queue.empty();
	_lock.unlock();
	return ret;
}

std::queue<Task>::size_type Threadpool::get_task_queue_size() const {
	_lock.lock();
	std::queue<Task>::size_type ret = _task_queue.size();
	_lock.unlock();
	return ret;
}
