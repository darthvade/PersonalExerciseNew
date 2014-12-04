#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base {
public:
	virtual void f() {
		cout << "Base::f()" << endl;	
	}
	virtual void g() {
		cout << "Base::g()" << endl;	
	}
	virtual void h() {
		cout << "Base::h()" << endl;	
	}
};

class Derive : public Base {
public:
	virtual void f() {
		cout << "Derive::d_f()" << endl;	
	}
	virtual void d_g() {
		cout << "Derive::d_g()" << endl;	
	}
	virtual void d_h() {
		cout << "Derive::d_h()" << endl;	
	}
};

int main() {
	Derive b;
	Fun pfun = NULL;
	cout << "虚函数表地址：" << (int *)&b << endl;
	cout << "虚函数表--第一个函数地址：" << (int *)*(int *)&b << endl;
	for(int i = 0; i < 5; ++i) {
		pfun = (Fun)*((int *)*(int *)&b + i);
		pfun();
	}
	return 0;
}
