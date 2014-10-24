#include <iostream>
#include "myStack.h"

using namespace std;

int main() {
	myStack<int> myst;
	myst.push(1);
	myst.push(2);
	myst.push(3);
	myst.push(4);
	myst.push(5);
	while(!myst.empty()) {
		cout << myst.top() << "->";
		myst.pop();
	}
	cout << endl;
	return 0;
}
