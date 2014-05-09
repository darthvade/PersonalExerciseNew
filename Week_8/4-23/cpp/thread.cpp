#include <iostream>
#include <pthread.h>
#include <cstddef>
#include <unistd.h>

using namespace std;

void *func(void *) {
	cout << "FUNC!" << endl;
	sleep(5);
	pthread_exit(0);
}

int main() {
	
	pthread_t tid;
	pthread_create(&tid, NULL, func, NULL);

	pthread_join(tid, NULL);

	return 0;
}
