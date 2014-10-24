#include "myQueue.h"
#include <iostream>

using namespace std;

int main() {
	myQueue<int> mq;
	mq.push(1);
	mq.push(2);
	mq.push(3);
	mq.push(4);
	mq.push(5);
	while(!mq.empty()) {
		cout << "fonrt:" << mq.front() << " --> " << "back:" << mq.back() << endl; 	
		mq.pop();
	}
	return 0;
}
