//vptl,vptr

#include <iostream>

using namespace std;

struct PointA {
	int a;
	int b;
};

struct PointB {
	virtual ~PointB() {}
	int a;
	int b;
};

int main() {
	PointA pa;
	PointB pb;
	cout << sizeof(int) << endl;
	cout << sizeof(pa) << endl;
	cout << sizeof(pb) << endl;
	return 0;
}
