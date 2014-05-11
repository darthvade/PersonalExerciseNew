#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream is("data");
	string temp;
	while(is >> temp) {
		cout << temp << endl;
	}
	ofstream os("data");
	os << "hello world!" << endl;
	return 0;
}
