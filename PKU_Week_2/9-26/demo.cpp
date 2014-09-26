#include <iostream>

using namespace std;

class Base1 {
public:
	Base1() {
		cout << "Constructor->Base1" << endl;
	}
private:
	int num;
};

class Base2 {
public:
	Base2() {
		cout << "Constructor->Base2" << endl;
	}
private:
	int num;
};

class Sub1 : public Base1, public Base2 {
public:
	Sub1() {
		cout << "Constructor->Sub1" << endl;
	}
private:
	int num;
};

int main() {
	Sub1 sb;	
	cout << sizeof(sb) << endl;
	return 0;
}
