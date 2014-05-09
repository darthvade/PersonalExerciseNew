#include "CondVar.h"
#include "mutex.h"

CondVar::CondVar(Mutex *mutex) {
	this->mutex = mutex;
	pthread_cond_init(&condvar, NULL);
}

CondVar::~CondVar() {
	pthread_cond_destroy(&condvar);
}

void CondVar::wait() {
	pthread_cond_wait(&condvar, &mutex->mutex);
}

void CondVar::notify() {
	pthread_cond_signal(&condvar);
}

void CondVar::notify_all() {
	pthread_cond_broadcast(&condvar);
}
