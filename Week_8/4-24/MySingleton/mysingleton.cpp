#include <iostream>

using namespace std;

class Base {
public:
	static Base& Instance() {
		static Base single;
		return single;
	}
	void print() {
		cout << "Singleton!" << endl;	
	}
private:
	Base() {};
	Base(const Base &);
	Base& operator=(const Base&);
	~Base() {};
};

int main() {
	cout << &Base::Instance() << endl;;
	cout << &Base::Instance() << endl;;
	cout << &Base::Instance() << endl;;
	cout << &Base::Instance().Instance().Instance() << endl;;
	return 0;
}
