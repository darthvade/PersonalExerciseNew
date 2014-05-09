#include "Thread.h"

int main() {
	Thread p1(5, "Hehe?!");
	Thread p2(10, "hello world!");
	p1.start();
	p2.start();
	p1.join();
	p2.join();
	return 0;
}
