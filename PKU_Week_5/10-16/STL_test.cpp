#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void cmp(stack<char> &s, queue<char> &q) {
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
	stack<char> st;
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
	queue<char> qu;
	while(p != input.end()) {
		qu.push(*p);
		++p;
	}
	cmp(st, qu);	
	return 0;
}
