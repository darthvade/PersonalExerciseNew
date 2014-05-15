#include <iostream>
#include <functional>

using namespace std;

class A {
public:
	void funcA() {
		cout << "funcA" << endl;
	}
	void funcAint(int i) {
		cout << "funcAint+" << i << endl;
	}
};

class B {
public:
	void funcB() {
		cout << "funcB" << endl;
	}
};

int main() {
	function<void ()> fun;
	A obja;
	B objb;
	fun = bind(&A::funcA, &obja);	
	fun();

	fun = bind(&A::funcAint, &obja, 100);
	fun();

	fun = bind(&B::funcB, &objb);
	fun();

	function<void (int)> func2;
	func2 = bind(&A::funcAint, &obja, placeholders::_1);
	func2(10086);
	return 0;
}
