#include "ProducerThread.h"

using namespace std;

ProducerThread::ProducerThread(WorkingQueue *wq, int frequent, Mutex *cout_lock) : 
	_p_id(0), _wq(wq), _frequent(frequent) , _cout_lock(cout_lock){
	srand(1000);
}

ProducerThread::~ProducerThread() {

}

void ProducerThread::start() {
	pthread_create(&_p_id, NULL, _producer_action, this);
}

void ProducerThread::join() {
	pthread_join(_p_id, NULL);
}

void* ProducerThread::_producer_action(void *args) {
	ProducerThread *pproducer = static_cast<ProducerThread *>(args);
	pproducer->_run();
	pthread_exit((void *)0);
}

void ProducerThread::_run() {
	while(true) {
		int pro = rand() % 1024;
		_wq->product(pro);
		_cout_lock->lock();
		cout << endl;
		cout << "No. "<< pthread_self() << " product num " << pro << endl;
		cout << endl;
		_cout_lock->unlock();
		sleep(_frequent);
	}
}
