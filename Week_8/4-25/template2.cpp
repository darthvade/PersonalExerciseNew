#include <iostream>
#include <string>

using namespace std;

template <class T>
class Base {
public:
	void echo() {
		std::cout << tmp << std::endl;
	}
private:
	T tmp;
};


int main() {

	Base<string> hehe;
	hehe.echo();

	return 0;
}
