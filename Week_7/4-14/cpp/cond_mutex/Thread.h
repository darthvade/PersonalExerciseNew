#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <string>

class Thread {
	public:
		Thread(int num, std::string s);
		~Thread();
		void start();
		void join();
		void run();
	private:
		int num;
		std::string s;
		pthread_t thread;
		static void* func(void *args);
};

#endif
