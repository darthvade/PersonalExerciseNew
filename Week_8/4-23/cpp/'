#include <iostream>
#include <pthread.h>
#include <cstddef>

void *func(void *) {

	pthread_exit(0);
}

int main() {
	
	pthread_t pthread_create(NULL, NULL, func, NULL);

	return 0;
}
