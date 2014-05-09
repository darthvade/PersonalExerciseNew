#include <stdio.h>
#include <pthread.h>
#include <malloc.h>

void freemem(void *args) {
	free(args);
	printf("clean up the memory!\n");
}

void *ThreadFunc(void *args) {
	char *p = (char *)malloc(10);
	pthread_cleanup_push(freemem, p);
	int i;
	for(i = 0; i < 10; i++) {
		printf("Hello, my name is Kevin!\n");
		sleep(1);
	}
	//pthread_exit((void*)3);
	pthread_cleanup_pop(1);
}

int main() {

	pthread_t ph_id;
	pthread_create(&ph_id, NULL, ThreadFunc, NULL);
	int i = 1;
	for(; i < 5; i++) {
		printf("Hello, nice to meet you!\n");
		sleep(1);
	}
	int retvalue = 0;
	pthread_join(ph_id, (void **)&retvalue);
	printf("%d\n", retvalue);
	return 0;
}
