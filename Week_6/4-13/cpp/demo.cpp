#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	try {
		throw runtime_error("Error!");
	} catch (runtime_error err){
		cout << err.what() << endl;
	}
}
