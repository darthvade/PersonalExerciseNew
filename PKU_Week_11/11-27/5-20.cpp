#include <iostream>
#include <string>

using namespace std;

int main() {
	bool flag = false;
	string input;
	string pre;
	while(cin >> input) {
		if(pre == input && input[0] >= 'A' && input[0] <= 'Z') {
			flag = true;
			break;			
		}
		pre = input;
	}
	if(flag) {
		cout << input << endl;
	} else {
		cout << "没有重复！" << endl;
	}
	return 0;
}
