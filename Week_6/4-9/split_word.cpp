#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "need arg!" << endl;
	}
	string s(argv[1]);
	vector<string> v;
	int pre = 0, pos = 0;
	size_t left = 0, right = 0;
	for(size_t ix = 0; ix != s.size(); ix++) {
		if(isalpha(s[ix])) {
			pre = pos;
			pos = 1;
		} else {
			pre = pos;
			pos = 0;
		}
		if(pre == 0 && pos == 1) {
			left = ix;
		}
		if(pre == 1 && pos == 0) {
			right = ix;
			v.push_back(s.substr(left, right - left));	
			pre = 0;
		}
		if(pos == 1 && ix == (s.size() - 1)) {
			v.push_back(s.substr(left, right - left));	
		}
	}	
	for(vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}
	return 0;
}
