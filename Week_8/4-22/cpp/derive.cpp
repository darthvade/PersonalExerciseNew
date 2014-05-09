#include <iostream>

using namespace std;

class A {
public:
	void test() {
		num = 999;
		cout << "in Class A " << num << endl;
	}
protected:
	int num;
};

class B : public A {
public:
	void setNum() {
		num = 1000000;
	}
};

int main() {
	A a;
	a.test();
	B b;
	b.setNum();
	b.test();
	return 0;
}
