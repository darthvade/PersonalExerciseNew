/**
* Polymorphism(多态性)
*/

#include<iostream>
using namespace std;
/*
class A {
	public:
		A(): i(10){}
		virtual void fun(){
			cout << "A::fun()" << endl;
		}
	private:
		int i;
};
*/
class Base {
	public:
		virtual void fun(){
			cout << "Base::fun()" << endl;
		}	
};
class Sub : public Base {
	public:
		virtual void fun(){
			cout << "Sub::fun()" << endl;
		}
};
int main(){
	/*	
	A a;
	a.fun();
	cout << sizeof(a) << endl;
	//int *p = (int*)&a;
	//cout << *(++p) << endl;
	*/
	Base base;
	Sub sub;
	sub.fun();
	return 0;
}
