#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>

#define N 5

pthread_mutex_t mutex;
pthread_cond_t empty;
pthread_cond_t full;


std::queue<int> source;

void *consumer(void *) {
	while(true) {
		pthread_mutex_lock(&mutex);	

		/***********************************/
		while(source.empty()) {
			std::cout << "queue is EMPTY!" << std::endl;
			pthread_cond_wait(&full, &mutex);	
		}
		std::cout << "consumer run!" << std::endl;
		source.pop();
		pthread_cond_signal(&empty);
		/***********************************/

		pthread_mutex_unlock(&mutex);
		sleep(5);
	}
	pthread_exit(0);
}

void *producer(void *) {
	while(true) {
		pthread_mutex_lock(&mutex);	

		/***********************************/
		while(source.size() == N) {
			std::cout << "queue is FULL!" << std::endl;
			pthread_cond_wait(&empty, &mutex);	
		}
		std::cout << "producer run!" << std::endl;
		source.push(999);
		pthread_cond_signal(&full);
		/***********************************/

		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(0);
}


int main() {
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&empty, NULL);
	pthread_cond_init(&full, NULL);


	pthread_t t_cons, t_prot;
	pthread_create(&t_cons, NULL, consumer, NULL);
	pthread_create(&t_prot, NULL, producer, NULL);


	pthread_join(t_cons, NULL);
	pthread_join(t_prot, NULL);

	return 0;
}
