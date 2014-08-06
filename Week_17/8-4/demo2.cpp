#include <iostream>

void func(std::initializer_list<int> input) {
	for(auto i = input.begin(); i != input.end(); ++i) {
		std::cout << *i << std::endl;
	}
	return;
}

int main() {
	func({9, 89, 768, 64, 3, 67});
	return 0;
}
