#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec1{1, 2, 3, 4, 5};
	std::vector<int> vec2{6, 7, 8, 9};
	std::cout << vec1.size() << std::endl;
	std::cout << vec2.size() << std::endl;
	auto origin = vec1.begin();
	auto iter = origin;
	while(++iter != vec1.end()) {
		std::cout << "-->" << *iter << std::endl;
	}
	std::swap(vec1, vec2);
	std::cout << vec1.size() << std::endl;
	std::cout << vec2.size() << std::endl;
	iter = origin;
	while(++iter != vec2.end()) {
		std::cout << "-->" << *iter << std::endl;
	}
	return 0;
}
