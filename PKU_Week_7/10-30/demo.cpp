#include <iostream>
#include <iterator>

using namespace std;

int main() {
	int* arry[10] = {};
	int* (&refarry)[10] = arry;
	for(int i = 0; i < 10; ++i) {
		refarry[i] = new int(10);
	}
	for(auto i : arry) {
		cout << i << endl;	
	}
	decltype(arry) newarry = {};
	for(auto i : newarry) {
		cout << i << endl;	
	}
	int *(*beginptr) = begin(arry);
	int *(*endptr) = end(arry);
	while(beginptr != endptr) {
		cout << *beginptr << endl;	
		++beginptr;
	}
	return 0;
}
