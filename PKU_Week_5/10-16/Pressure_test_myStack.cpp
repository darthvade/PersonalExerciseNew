#include "myStack.h"
#include <iostream>

using namespace std;

int main() {
	myStack<int> mst;
	for(long long i = 0; i <= 1000000000; ++i) {
		mst.push(i);	
	}
	cout << mst.size() << endl;
	return 0;
}
