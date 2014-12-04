#include <iostream>
#include <string>

using namespace std;

int main() {
	int counter = 0;
	int max_counter = 0;
	string input;
	string pre;
	string max_str;
	while(cin >> input) {
		if(input == pre) {
			++counter;
			pre = input;
		} else {
			if(counter > max_counter) {
				max_counter = counter;
				max_str = pre;
				counter = 0;
			}
			pre = input;
			counter = 1;
		}
	}
	cout << max_str << "连续出现了" << max_counter << endl;
	return 0;
}
