#include <iostream>

using namespace std;

class B;

class A {
public:
	A() {
		_a = 100;
		_class_b.rgst(this);
	}
	int getA() {
		return _a;
	}
private:
	int _a;
	B _class_b;
};

class B {
public:
	B() {
		_b = 10;
	}
	void rgst(A *p) {
		_p = p;
	}
	void debug() {
		int _a = _p->getA();
		cout << _b + _a << endl;
	}
private:
	int _b;
	A *_p;
};



int main() {
	A a;
	return 0;
}
