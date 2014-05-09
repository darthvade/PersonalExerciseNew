#include "Threadpool.h"
#include <unistd.h>

int main() {
	Threadpool pool(10);
	pool.start_threadpool();

	while(true) {
		Task tmp;
		tmp.solve = "hello wprld!";
		pool.add_task_queue(tmp);
		//sleep(10);
	}
	return 0;
}
