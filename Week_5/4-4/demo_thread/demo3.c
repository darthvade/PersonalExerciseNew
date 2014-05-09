#include <stdio.h>
#include <pthread.h>
#include <malloc.h>

void *ThreadFunc(void *args) {
	char *p = (char *)malloc(10);
	int i;
	for(i = 0; i < 10; i++) {
		printf("hello, my name is Kevin! \n");
		sleep(1);
	} 
	free(p);
	printf("p is freed\n");
	pthread_exit((void*)3);
}

int main() {
	pthread_t pthid;
	pthread_create(&pthid, NULL, ThreadFunc, NULL);
	int i = 0;
	for(; i < 5; i++) {
		printf("Hello , nice to meet you!\n");
		sleep(1);
	}
	int revalue = 0;
	pthread_join(pthid, (void**)&revalue);
	printf("revalue is %d\n", revalue);
	return 0;
}
