#include <iostream>


using namespace std;

class A {
public:
A() : data(0) {}
int data;
void f() {
	cout << "A::f()" << endl;
}
};

class B {
public:
B() : data(0) {}
int data;
void f() {
	cout << "B::f()" << endl;
}
};


int main() {
	A a;
	B b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	return 0;
}
