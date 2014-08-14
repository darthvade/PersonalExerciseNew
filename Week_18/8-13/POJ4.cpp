#include <iostream>

using namespace std;

int main() {
	int input;
	cin >> input;
	if(input == 1) {
		cout << 1 << endl;
		return 0;
	}
	int counter = 1;
	for(int i = 1; i <= input; ++i) {
		int temp = i;
		for(int j = i + 1; j <= input; ++j) {
			temp += j;	
			if(temp < input) {
				continue;
			}
			if(temp == input) {
				counter++;
				break;
			}
			if(temp > input) {
				break;
			}
		}
	}
	cout << counter << endl;
	return 0;
}
