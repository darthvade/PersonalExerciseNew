#include <iostream>
#include <utility>

using namespace std;

int main() {

	pair<string, string> p;
	p.first = string("apple");
	p.second = string("苹果");

	cout << p.first << " " << p.second <<  endl;
}
