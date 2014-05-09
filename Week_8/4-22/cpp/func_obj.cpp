#include <iostream>

using namespace std;

struct Absint {
	int operator() (int val) {
		return (val > 0) ? val : -val;
	}
};

int main() {

	int i = -99;
	Absint abs;
	cout << abs(i) << endl;
	return 0;
}
