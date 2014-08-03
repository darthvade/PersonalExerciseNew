#include "./MyClass.h"

MyClass::MyClass(int i, int j) : x(i), y(j) {};

void MyClass::print() {
	std::cout << "x-> " << x << std::endl; 	
	std::cout << "y-> " << y << std::endl; 	
	std::cout << std::endl;
}
