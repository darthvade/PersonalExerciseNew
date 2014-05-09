#ifndef __MYCOMPLEX_H__
#define __MYCOMPLEX_H__

#include <iostream>

class MyComplex {
	friend std::ostream& operator<< (std::ostream&, const MyComplex&);
	friend std::istream& operator>> (std::istream&, MyComplex&);
public:
	MyComplex();
	MyComplex(int, int);
	MyComplex(const MyComplex&);
	MyComplex& operator=(const MyComplex&);
	MyComplex operator+(const MyComplex&);
	MyComplex operator-(const MyComplex&);
	MyComplex operator*(const MyComplex&);
	bool operator==(const MyComplex&);
	~MyComplex();
private:
	int _r;
	int _i;
};


#endif
