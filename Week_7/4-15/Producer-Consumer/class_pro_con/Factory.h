#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "Mutex.h"
#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "WorkingQueue.h"
#include <vector>

class Factory {
	public:
		Factory(std::size_t num_consumer,
				std::size_t fre_consumer,
				std::size_t num_producer,
				std::size_t fre_producer);
		~Factory();	
		ProducerThread& create_one_producer(std::size_t fre_producer);
		ConsumerThread& create_one_consumer(std::size_t fre_consumer);
		void start_all();
		void join_all();
	private:
		std::size_t _num_consumer;
	   	std::size_t _fre_consumer;	
		std::size_t _num_producer;
		std::size_t _fre_producer;
		WorkingQueue _wq;
		Mutex _cout_lock;
		std::vector<ProducerThread> _vproducer;
		std::vector<ConsumerThread> _vconsumer;
};

#endif
