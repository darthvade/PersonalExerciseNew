#include <stdio.h>
#include <pthread.h>

void CleanFunc(void *pArg) {
	printf("CleanFunc(%d)\n", (int)pArg);
}

void *ThreadFunc(void *pArg) {
	pthread_cleanup_push(CleanFunc, (void *)1);
	pthread_cleanup_push(CleanFunc, (void *)2);
	sleep(1);
	//pthread_exit(NULL);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
}

int main() {
	pthread_t th_id;
	pthread_create(&th_id, NULL, ThreadFunc, (void*)2);
	pthread_join(th_id, NULL);
	return 0;
}
