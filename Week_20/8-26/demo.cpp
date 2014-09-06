// using Priority Q to implement FIFO Q and Stack
// CLRS v3.0 6.5-7

#include <queue>
#include <iostream>
#include <vector>

struct Data {
	Data(int k, int v) : key(k), value(v) {}
	int key;
	int value;
};

class Cmp {
	public:
		Cmp(const bool &flag = false) : flag(flag) {}	
		bool operator() (Data &lv, Data &rv) const {
			if(flag) 
				return lv.key > rv.key;
			else 
				return lv.key < rv.key;	
		}
	private:
		bool flag;
};

class FIFOQ {
	public:
		FIFOQ(bool QorS) : q(Cmp(QorS)) {}
		void push(int i) {
			q.push(Data(q.size() + 1, i));	
		}
		int front() {
			return q.top().value;	
		}
		int back() {
			return 0;
		}
		void pop() {
			q.pop();	
		}
		int size() {
			return q.size();	
		}
		bool empty() {
			return q.empty();	
		}
	private:
		std::priority_queue<Data, std::vector<Data>, Cmp> q;
};

int main() {
	FIFOQ fq(true); //FIFO Q
	fq.push(1);
	fq.push(2);
	fq.push(3);
	fq.push(4);
	while(!fq.empty()) {
		std::cout << fq.front() << std::endl;
		fq.pop();	
	}
	FIFOQ st(false); //Stack
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while(!st.empty()) {
		std::cout << st.front() << std::endl;
		st.pop();	
	}
	return 0;
}
