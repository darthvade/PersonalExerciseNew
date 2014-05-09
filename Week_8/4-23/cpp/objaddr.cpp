/*打印成员地址
 *成员函数暂时地址无法打印
 *
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Base {
public:
	void test1(){};
	static void test2(){};
	void test3(){};
	void debug() {
		cout << "a: " << &a << endl;
		cout << "b: " << &b << endl;
	}
private:
	int a;
	int b;
};

int main() {
	Base a;
	a.debug();
	return 0;
}
