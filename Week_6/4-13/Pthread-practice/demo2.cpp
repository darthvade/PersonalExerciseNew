#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREAD 5
	
struct args {
	int data;
	pthread_mutex_t mutex;
};

typedef struct args ARG;

void *func(ARG *arg) {
	pthread_mutex_lock(&arg->mutex);
	cout << endl;
	cout << "func started" << endl;
	cout << (*arg).data << endl;
	(*arg).data	+= 1;
	cout << (*arg).data << endl;
	cout << "func finished" << endl;
	cout << endl;
	pthread_mutex_unlock(&arg->mutex);
	pthread_exit((void *) 0);
}

int main() {

	pthread_t thread[NUM_THREAD];
	ARG arg;
	arg.data = 1000;
	
	pthread_mutex_init(&arg.mutex, NULL);

	//对不符合回调函数类型的进行强制类型转换
	for(int i = 0; i != NUM_THREAD; ++i) {
		pthread_create(thread + i, NULL, (void *(*)(void *))func, &arg);
	}

	pthread_mutex_destroy(&arg.mutex);

	for(int i = 0; i != NUM_THREAD; ++i) {
		pthread_join(thread[i], NULL);
	}

	cout << "main finished!" << endl;

	pthread_exit(NULL);
}
