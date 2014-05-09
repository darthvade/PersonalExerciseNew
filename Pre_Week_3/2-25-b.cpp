/**
*
*/
#include<iostream>

using namespace std;

int main() {
	int *p;
	p = new int[10];
	for(int i = 0; i < 10; i++) {
		p[i] = i;
	}
	for(int i = 0; i < 20; i++) {
		cout << i << " --> " << p[i] << endl;
	}// access more than exist
	delete [] p;
	cout << p[9] << endl;// access after delete
	return 0;
}
