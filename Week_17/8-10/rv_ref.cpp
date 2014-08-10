#include <iostream>

int main() {
	int val = 90;
	int &&rv_ref = val * 10;
	std::cout << rv_ref << std::endl;
	return 0;
}
