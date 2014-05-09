#include "MyComplex.h"
#include <iostream>

using namespace std;

int main() {
	/*
	MyComplex a(3, 4);
	MyComplex b(4, 5);
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << (a == b) << endl;
	*/
	MyComplex complex_obj1 ;

	MyComplex complex_obj2(3,4);

	MyComplex complex_obj3 , complex_obj4 ;

	cin >> complex_obj3 >> complex_obj4 ;

	cout << complex_obj2 + complex_obj3 << endl ;

	cout << complex_obj2 - complex_obj3 << endl ;

	cout << complex_obj2 * complex_obj4 << endl ;

	cout << (complex_obj2 == complex_obj3) << endl ;

	MyComplex  complex_obj5(complex_obj2) ;

	cout << complex_obj5 << endl;;

	MyComplex  complex_obj6 ;

	complex_obj6 = complex_obj2 ;

	cout << complex_obj6 << endl ;
	return 0;
}
