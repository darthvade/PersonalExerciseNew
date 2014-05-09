#include <iostream>

using std::string;

int main() {
	int *pa = new int;
	int *pb = new int(5);
	int *pc = new int[5];
	std::cout << *pa << std::endl;
	std::cout << *pb << std::endl;
	std::cout << *pc << std::endl;
	string *pd = new string("hello world!");
	string *pe = new string[5];
	std::cout << *pd << std::endl;
	std::cout << (*pd).size() << std::endl;
	std::cout << (*pe).size() << std::endl;
	delete pd;
	delete [] pe;
	return 0;
}
