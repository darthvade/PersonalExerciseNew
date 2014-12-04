#include <iostream>
#include <string>
using namespace std;

string convert(int score) {
	if(score == 100) {
		return "A++";
	}
	else {
		return "hehe";
	}
}

int main() {
	int sum = 0 ;
	int val = 1;
	while(sum+=val, ++val, val <= 10);
	cout << sum << endl;
	cout << convert(100) << endl;
	const int hehe1 = 1, hehe2 = 2;
	switch(sum) {
		case hehe1:break;
		case hehe2:break;
	}
	return 0;
}
