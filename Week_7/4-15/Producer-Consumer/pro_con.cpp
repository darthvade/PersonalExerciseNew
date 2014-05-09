#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>

using namespace std;

queue<int> Q;

pthread_mutex_t gmutex;

pthread_cond_t full;

pthread_cond_t empty;

void *producer_func(void *) {
	while(1) {

 		pthread_mutex_lock(&gmutex);
 			 
		while(Q.size() == 5) {
			cout << "Buffer is full!" << endl;
 			pthread_cond_wait(&empty, &gmutex);
 		}
		Q.push(1);
		pthread_cond_signal(&full);
								
 		pthread_mutex_unlock(&gmutex);
	}
	pthread_exit((void *)0);
}

void *consumer_func(void *args) {
	while(1){
		pthread_mutex_lock(&gmutex);

		while(Q.empty()) {
			cout << "consumer" << (int)args << " begin wait" << endl;
			pthread_cond_wait(&full, &gmutex);
		}
		int num = Q.front();
		Q.pop();
		cout << "consumer" << (int)args << " get a num " << num << endl;

		pthread_cond_signal(&empty);

		pthread_mutex_unlock(&gmutex);
	}
	pthread_exit((void *)0);
}


int main() {
	pthread_mutex_init(&gmutex, NULL);
	pthread_cond_init(&full, NULL);
	pthread_cond_init(&empty, NULL);

	pthread_t thread[3];
	
	pthread_create(&thread[0], NULL, producer_func, NULL);
	pthread_create(&thread[1], NULL, consumer_func, (void *)1);
	pthread_create(&thread[2], NULL, consumer_func, (void *)2);

		
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_mutex_destroy(&gmutex);
	pthread_cond_destroy(&full);
	pthread_cond_destroy(&empty);
	return 0;
}
