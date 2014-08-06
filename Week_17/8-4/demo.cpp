#include <iostream>
#include <memory>

int main() {
	auto ptr = std::make_shared<int>(1000);
	auto ptr2 = ptr;
	auto ptr3 = ptr;
	std::cout << *ptr << std::endl;
	std::cout << ptr.use_count() << std::endl;
	return 0;
}
