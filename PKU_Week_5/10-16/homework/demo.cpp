#include <iostream>
#include <vector>
#include "myStack.h"
#include "myQueue.h"
#include <string>

using namespace std;

//判断一个栈和一个队列中的字符序列是否相匹配
void cmp(myStack<char> &s, myQueue<char> &q) {
	//比较栈和队列中的头元素，若相等，则分别出栈和队列
	//若不等，循环停止
	while(!s.empty() || !q.empty()) {
		if(s.top() == q.front()) {
			s.pop();
			q.pop();
			continue;
		} else {
			break;
		}	
	}
	//若最后栈和队列都为空，则两个字符串相匹配，
	//若至少有一个不为空，则两个字符串不匹配
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
	//将&分隔符左边的字符压入栈中
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
	//将&符右边的字符输入队列
	myQueue<char> qu;
	while(p != input.end()) {
		qu.push(*p);
		++p;
	}
	//判断一个栈和一个队列中的字符序列是否相匹配
	cmp(st, qu);	
	return 0;
}
