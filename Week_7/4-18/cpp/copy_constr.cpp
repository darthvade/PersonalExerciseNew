#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
	String() {
		_pstr = new char;
		_pstr[0] = '\0';
	}
	String(const char *copy) {
		_pstr = new char[strlen(copy) + 1];
		strcpy(_pstr, copy);
	}
	String(const String& copy) {
		_pstr = new char[strlen(copy._pstr) + 1];
		strcpy(_pstr, copy._pstr);
	}
	String& operator=(const String& s) {
		delete _pstr;
		_pstr = new char[strlen(s._pstr) + 1];
		strcpy(_pstr, s._pstr);	
		return *this;
	}
	~String() {
		delete _pstr;
	}
	void debug() {
		cout << _pstr << endl;
	}
private:
	char *_pstr;
};

int main() {
	String s("Hello");
	String s2(s);
	s2.debug();
	String s3("Hou are you?");
	s3.debug();
	s2 = s3;
	s2.debug();
	return 0;
}
