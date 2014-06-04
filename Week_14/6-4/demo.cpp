#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char p1[] = "hello";
	char p2[] = "abcdefg";
	strcpy(p1, p2);
	cout << p1 << endl;
	cout << p2 << endl;
	return 0;
}
