#include <iostream>

int main() {
	int *p1 = new int(99);
	int *p2 = new int(0);
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	delete p1;
	int *p3 = new int;
	std::cout << *p3 << std::endl;
	return 0;
}
