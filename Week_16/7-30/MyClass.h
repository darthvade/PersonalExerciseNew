#ifndef __MYCLASS__
#define __MYCLASS__

#include <iostream>

class MyClass {
public:
	MyClass() = default;
	MyClass(int i, int j);
	~MyClass() = default;
	void print();
private:
	int x = 0;
	int y = 0;
};

#endif
