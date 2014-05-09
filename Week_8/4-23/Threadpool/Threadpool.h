#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <queue>
#include <vector>
#include "MutexLock.h"
#include "Condition.h"
#include "Noncopyable.h"
#include "Workthread.h"

struct Task {
	int _num;
};

class Threadpool : public Noncopyable {
public:
	Threadpool(std::vector<Workthread>::size_type max_thread);
	~Threadpool();

	void start_threadpool();
	void stop_threadpool();

	bool add_task_queue(Task task);
	bool get_task_queue(Task &task);

	bool is_task_queue_empty() const;
	std::queue<Task>::size_type get_task_queue_size() const;
private:
	std::queue<Task> _task_queue;
	std::vector<Workthread>::size_type _max_thread;
	std::vector<Workthread> _thread_vector;

	bool _is_started;

	mutable Mutexlock _lock;
	mutable Condition _cond;
};

#endif
