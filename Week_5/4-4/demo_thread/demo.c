#include <stdio.h>
#include <pthread.h>

void *ThreadFunc(void *pArg) {
	int i = 0;
	for(; i < 10; i++) {
		printf("Hi, I'm child thread, arg is: %d\n", (int)pArg);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t th_id;
	pthread_create(&th_id, NULL, ThreadFunc, (void *)123);
	int i = 0;
	for(; i < 10; i++) {
		printf("Main thread, child thread id is %x \n", th_id);
		sleep(1);
	}
	return 0;
}
