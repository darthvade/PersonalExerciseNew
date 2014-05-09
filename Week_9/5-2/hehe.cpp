#include <iostream>

class A {
public:
	void test();
	typedef std::string::size_type index;
private:
	index height;
};

int main() {

	A a;
	a.test();
	A::index weight;
	weight = 100;
	return 0;
}
