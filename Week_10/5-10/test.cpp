#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int main() {

	clock_t begin;
	time(&begin);
	double i = 1.0;

	while(true) {
		clock_t end;
		time(&end);
		double gap = difftime(end, begin);
		//cout << gap << endl;
		if(gap == i) {
			cout << "one minute!" << endl;
			++i;
		}
	}

	return 0;
}
