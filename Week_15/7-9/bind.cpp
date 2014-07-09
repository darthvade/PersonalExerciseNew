#include <iostream>
#include <functional>
#include <string>

using namespace std;

using namespace std::placeholders;

void func(int a, const string &input) {
	cout << a << endl << input <<endl;
}

int main() {
	auto newfunc = bind(func, 1000, _1);
	newfunc("Hello world!");
	return 0;
}
