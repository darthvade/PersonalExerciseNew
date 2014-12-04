#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int a, b;
	while(cin >> a >> b) {
		try {
			cout << a / b << endl;
		} catch (std::runtime_error e) {
			cout << e.what() << endl;
			cout << "Try again!" << endl;	
		}
	}
	return 0;
}
