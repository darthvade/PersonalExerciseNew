#include <iostream>

using namespace std;

int func(int input) {
	int result = 0;
	while(input) {
		int temp = input % 10;	
		result = result * 10 + temp;
		input /= 10;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << func(func(a) + func(b)) << endl;	
	}
	return 0;
}
