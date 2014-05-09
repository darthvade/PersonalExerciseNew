#include "String.h"

using namespace std;

int main() {
	/*
	String s1;
	String s2("hello");
	String s3("world");
	s1 = s2 + s3;
	s1.debug();
	*/
	String s1 = "test";
	s1 = s1;
	s1.debug();
	s1 = "hehe";
	s1.debug();
	cout << s1[3] << endl;
	return 0;
}
