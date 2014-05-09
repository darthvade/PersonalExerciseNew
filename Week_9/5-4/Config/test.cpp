#include "Config.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	Config conf(argv[1]);	
	cout << conf[0] << endl;
	cout << conf[1] << endl;
	cout << conf[2] << endl;
	cout << conf[3] << endl;
	cout << conf[4] << endl;
	cout << conf[5] << endl;
	return 0;
}
