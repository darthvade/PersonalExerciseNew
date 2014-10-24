#include <iostream>
#include <vector>
#include "myStack.h"
#include "myQueue.h"
#include <string>

using namespace std;

void cmp(myStack<char> &s, myQueue<char> &q) {
	while(!s.empty() || !q.empty()) {
		if(s.top() == q.front()) {
			s.pop();
			q.pop();
			continue;
		} else {
			break;
		}	
	}
	if(s.empty() && q.empty()) {
		cout << "pattern matching!" << endl;	
	} else {
		cout << "pattern NO matching!"<< endl;
	}
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	string input(argv[1]);
	myStack<char> st;
	auto p = input.begin();
	while(p != input.end()) {
		if(*p != '&') {
			st.push(*p);	
		} else {
			++p;
			break;	
		}
		++p;
	}
	myQueue<char> qu;
	while(p != input.end()) {
		qu.push(*p);
		++p;
	}
	cmp(st, qu);	
	return 0;
}
