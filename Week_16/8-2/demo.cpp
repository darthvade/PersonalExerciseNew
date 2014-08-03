#include <iostream>
#include <csignal>
#include <sys/select.h>
#include <unistd.h>

void func(int x) {
	std::cout << x << " --> " << "signal me!!" << std::endl;
}

int main() {
	signal(SIGINT, func);

	while(true) {
		struct timeval time;
		time.tv_usec = 0;
		time.tv_sec = 1;
		select(0, NULL, NULL, NULL, &time);
		std::cout << "in the loop!!" << std::endl;
	}

	return 0;
}
