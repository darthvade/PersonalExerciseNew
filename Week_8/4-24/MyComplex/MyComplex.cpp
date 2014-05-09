#include "MyComplex.h"

MyComplex::MyComplex() : _r(0), _i(0) {}

MyComplex::MyComplex(int r, int i) : _r(r), _i(i) {}

MyComplex::~MyComplex() {};

MyComplex::MyComplex(const MyComplex& other) {
	_r = other._r;
	_i = other._i;
}

MyComplex& MyComplex::operator=(const MyComplex& other) {
	_r = other._r;
	_i = other._i;
	return *this;
}

MyComplex MyComplex::operator+(const MyComplex& other) {
	MyComplex result(this->_r + other._r, this->_i + other._i);
	return result;
}

MyComplex MyComplex::operator-(const MyComplex& other) {
	MyComplex result(this->_r - other._r, this->_i - other._i);
	return result;
}

MyComplex MyComplex::operator*(const MyComplex& other) {
	MyComplex result;
	result._r = (this->_r * other._r) - (this->_i * other._i);
	result._i = (this->_r * other._i) + (this->_i * other._r);
	return result;
}

bool MyComplex::operator==(const MyComplex& other) {
	if(this->_r == other._r && this->_i == other._i) {
		return true;
	} else {
		return false;
	}
}

std::ostream& operator<< (std::ostream& os, const MyComplex& cplx) {
	if(cplx._i > 0) {
		os <<  cplx._r << "+" << cplx._i << "i";
	} else if(cplx._i < 0) {
		os <<  cplx._r << cplx._i << "i";
	} else {
		os <<  cplx._r;
	}
	return os;
}

std::istream& operator>> (std::istream& in, MyComplex& cplx) {
	in >> cplx._r >> cplx._i;	
	if(!in) {
		cplx = MyComplex();
	}
	return in;
}
