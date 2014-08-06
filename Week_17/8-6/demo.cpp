#include <iostream>
#include <memory>

int main() {
	std::allocator<int> alloc;
	auto const p = alloc.allocate(10);
	*p = 100;
	std::cout << *p << std::endl;	
	return 0;
}
