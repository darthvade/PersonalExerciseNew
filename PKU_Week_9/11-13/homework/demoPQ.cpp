#include "./PriorityQueue.h"
#include <iostream>
using namespace std;

template <typename T>
struct mygreater {
	bool operator() (const T &a, const T &b) {
		return a > b ? true : false;	
	}
};

template <typename T>
struct myless {
	bool operator() (const T &a, const T &b) {
		return a < b ? true : false;	
	}
};


int main() {
	PriorityQueue<int, myless<int>> pq;
	for(int i = 1; i <= 10000; ++i) {
		pq.insert(i, i);
	}
	while(!pq.empty()) {
		cout << pq.top().data << endl;
		pq.pop();	
	}
	return 0;
}
