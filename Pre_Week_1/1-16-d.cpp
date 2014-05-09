/**
* upcast "向上造型"
*/

#include<iostream>

using namespace std;

class A {
	public:
		void funA() {
			cout << "A::fun()" << endl;
		}
};

class B : public A {
	public:
		void funB() {
			cout << "B::fun()" << endl;
		}
};


int main(){
	B b;
	A& a = b;
	a.funA();
	return 0;
}
