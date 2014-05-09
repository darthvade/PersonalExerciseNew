/**
*
*/
#include<iostream>

int n;

int & setValue() {
	return n;
}

using namespace std;

int main() {
	setValue() = 99;
	cout << n << endl;
}
