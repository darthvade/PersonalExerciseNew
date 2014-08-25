//POJ-3367
//错误，没有考虑字母重复的问题......
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

char memory[256][2];

typedef string::iterator strIter;

char createTree(string &input) {
	memset(memory, 0, 256 * 2 * sizeof(char));
	stack<char> st;
	char root;
	strIter str = input.begin();
	while(str != input.end()) {
		if(islower(*str)) {
			st.push(*str);
		} else {
			memory[(int)*str][1] = st.top();
			st.pop();
			memory[(int)*str][0] = st.top();
			st.pop();
			root = *str;
			st.push(*str);
		}
		++str;
	}
	return root;
}

string trverse(char root) {
	string output;
	queue<char> q;
	q.push(root);
	while(!q.empty()) {
		output.push_back(q.front());	
		if(memory[(int)q.front()][0]) {
			q.push(memory[(int)q.front()][0]);
			q.push(memory[(int)q.front()][1]);
		}
		q.pop();
	}	
	memset(memory, 0, 256 * 2 * sizeof(char));
	return output;
}

void print(string &output) {
	string::reverse_iterator iter = output.rbegin();
	while(iter != output.rend()) {
		cout << *iter;	
		++iter;
	}	
	cout << endl;
}

int main() {
	int ncase;
	cin >> ncase;
	while(ncase--) {
		string input;
		cin >> input;
		//procedure
		char root = createTree(input);	
		string output = trverse(root);
		print(output);
	}
	return 0;
}
