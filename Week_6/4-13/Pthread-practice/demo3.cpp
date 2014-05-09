#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define NUM_WORKER_THREADS 2

using namespace std;

struct ARG {
	int data;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
};

typedef struct ARG Arg;

void *func_boss(Arg *arg) {
	pthread_mutex_lock(&arg->mutex);
	
	cout << endl;
	cout << "boss begin!" << endl;

	pthread_cond_wait(&arg->cond, &arg->mutex);
	cout << "Boss: GOOD!" << endl;

	cout << "boss end!" << endl;
	cout << endl;

	pthread_mutex_unlock(&arg->mutex);
	pthread_exit((void *)0);
}

void *func_worker(Arg *arg) {
	while(1) {

		pthread_mutex_lock(&arg->mutex);

		cout << endl;
		cout <<  pthread_self() << endl;
		cout << "worker begin!" << endl;
		cout << arg->data << endl;
		
		sleep(1);
		arg->data += 1;
		if(arg->data == 5) {
			pthread_cond_signal(&arg->cond);
			pthread_mutex_unlock(&arg->mutex);
			break;
		}

		cout << arg->data << endl;
		cout << "worker end!" << endl;
		cout << endl;

		pthread_mutex_unlock(&arg->mutex);
	}

	pthread_exit((void *)0);
}

int main() {

	Arg arg;
	arg.data = 0;

	pthread_t thread[NUM_WORKER_THREADS];
	pthread_t boss;

	//初始化锁和条件变量
	pthread_mutex_init(&arg.mutex, NULL);
	pthread_cond_init(&arg.cond, NULL);

	pthread_create(&boss, NULL, (void *(*)(void *))func_boss, &arg);
	for(int i = 0; i != NUM_WORKER_THREADS; ++i) {
		pthread_create(thread + i, NULL, (void *(*)(void *))func_worker, &arg);
	}
/*
	for(int i = 0; i != NUM_WORKER_THREADS; ++i) {
		pthread_join(thread[i], NULL);
	}
*/	
	pthread_join(boss, NULL);

	pthread_mutex_destroy(&arg.mutex);
	pthread_cond_destroy(&arg.cond);
	pthread_exit(NULL);
}
