/**
* "const" & "references" practice
*/

#include<iostream>
using namespace std;

class A {
	private: 
		int i;
	public:
		A(): i(0) {}
		void fun(){
			cout << "fun()" << endl;
		}
		void fun() const {
			cout << "fun() const" << endl;
		}
};

int x = 10;

int& fun(){
	return x;
}

int main(){
	/*
	const char *s = "Hello world!";
	cout << s << endl;
	s[0] = 'B';
	cout << s << endl;
	*/
	/*
	const A a;
	a.fun();
	*/
	/*
	int a = 10;
	int& b = a;
	cout << b << endl;
	cout << ++b << endl;	
	cout << &a << endl;
	cout << &b << endl;
	*/
	int a = 10;
	//const int* b = &a;//（const在*的左边）说明
			    //不可以通过指针b来修改a的值（但可以通过其他方式改变a的值，比如a自增一；同时b的指向可以修改）
	int* const b = &a;  //（const在*的右边）说明
			    //b仅仅可以指向a,而不可以指向其他对象（但a的值，既可以通过b改变，也可以通过其他方式改变，比如自增一）
	a++;
	cout << ++(*b) << endl;
	fun() = 10000;
	cout << x << endl;
	return 0;
}
