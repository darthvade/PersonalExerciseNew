#include "Smartptr.h"
#include "String.h"
#include <iostream>

using namespace std;

int main() {
	Smartptr p(new String("hehe"));
	cout << *p << endl;
	return 0;
}
