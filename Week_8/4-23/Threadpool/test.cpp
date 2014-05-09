#include "Threadpool.h"
#include <unistd.h>

int main() {
	Threadpool pool(10);
	pool.start_threadpool();

	while(true) {
		Task tmp;
		tmp._num = 8;
		pool.add_task_queue(tmp);
		//sleep(10);
	}
	return 0;
}
