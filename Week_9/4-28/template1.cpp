#include <iostream>
#include <string>

template <class T> class Base {
public:
	Base(T ini) : data(ini) {}; 
private:
	T data;
};

int main() {
	Base<std::string> b("string");
	std::cout << "Hello!" << std::endl;
	return 0;
}
