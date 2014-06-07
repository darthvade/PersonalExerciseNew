#include <iostream>

using namespace std;

class A {
public:
	int x;
	int y;
};

A b;

int main() {

	A a;
	cout << a.x << " " << a.y << endl; 	
	cout << b.x << " " << b.y << endl; 	

	return 0;
}
