/**
* static member in C++
*/
#include<iostream>

using namespace std;

class A {
	public:
		/**此句语法错误。
		A():i(0) {}//初始化列表只能初始化非静态变量！
		*/
		A() {
			i = 10;
		}
		~A() {}
		A(const A& a) {}
		static void print() {
			cout << i << endl;
		}
		void set(int ii) {
			i = ii;
		}
	private:
		static int i;
};

int A::i;

int main() {
	A a, b;
	a.set(99);
	b.print();
	A::print();
	return 0;
}
