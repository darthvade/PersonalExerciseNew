#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool compare(const T &t1, const T &t2) {
	return t1 > t2;
}

int main() {
	cout << compare(string("aaa"), string("bbb")) << endl;;
	cout << compare(88, 90) << endl;;
	return 0;
}
