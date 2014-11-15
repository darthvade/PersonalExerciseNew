#include <iostream>

using namespace std;

int main() {
	unsigned long u11 = 3, u12 = 7;
	std::cout << (u11 & u12) << std::endl;
	std::cout << (u11 | u12) << std::endl;
	std::cout << (u11 && u12) << std::endl;
	std::cout << (u11 || u12) << std::endl;
	int x[10];
	int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}
