#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *pThreadFunc(void *args) {
	pthread_mutex_lock(&lock);
//	pthread_mutex_lock(&lock);
	pthread_mutex_trylock(&lock);
	printf("hello\n");
	sleep(1);
	pthread_exit(NULL);
}

int main() {
	pthread_t pth_id = 0;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&pth_id, NULL, pThreadFunc, NULL);
	pthread_join(pth_id, NULL);
	pthread_mutex_destroy(&lock);
}
