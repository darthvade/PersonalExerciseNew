//POJ-1401

#include <iostream>

using namespace std;

unsigned long long int func(unsigned long long int n) {
	unsigned int sum = 0 ;
	for(unsigned long long int i = 5; i <= n; i *= 5) {
		sum += n / i;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		int temp;
		cin >> temp;
		cout << func(temp) << endl;
	}
	return 0;
}
