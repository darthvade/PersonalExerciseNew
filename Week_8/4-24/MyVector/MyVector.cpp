#include "MyVector.h"
#include <cstring>

MyVector::MyVector() : _myptr(0), _size(0), _capacity(0) {
}

MyVector::MyVector(int n) : _size(n), _capacity(n) {
	_myptr = new int[n];	
	memset(_myptr, 0, n);
}

MyVector::MyVector(int *begin, int *end) {
	if(begin <= end) {
		unsigned int n = end - begin;
		_size = n;
		_capacity = n;
		_myptr = new int[n];
		memcpy(_myptr, begin, n * sizeof(int));
	}
}

MyVector::~MyVector() {
	delete[] _myptr;
}

MyVector::MyVector(const MyVector& other) {
	_myptr = new int[other._capacity];
	memcpy(_myptr, other._myptr, other._capacity * sizeof(int));
	_size = other._size;
	_capacity = other._capacity;
}

bool MyVector::operator!= (const MyVector& other) const {
	if(this->_myptr != other._myptr) {
		return true;
	} else {
		return false;
	}
}

MyVector& MyVector::operator= (const MyVector& other) {
	if(*this != other) {
		delete[] this->_myptr;	
		this->_myptr = new int[other._capacity];
		memcpy(_myptr, other._myptr, other._capacity);
		this->_size = other._size;
		this->_capacity = other._capacity;
	} 	
	return *this;
}

unsigned int MyVector::size() {
	return _size;
}

unsigned int MyVector::capacity() {
	return _capacity;
}
	
int& MyVector::operator[] (const unsigned int index){
	return this->_myptr[index];
}

void MyVector::insert(unsigned int n, int elem) {
	if(n > this->_size) {
		return;	
	} else if (n == 0 && this->_size == 0) {
		_myptr = new int(elem);
		_size++;
		_capacity++;
	} else if (n <= this->_size && this->_size + 1 == this->_capacity) {
		_myptr[n] = elem;	
		_size++;
	} else if (n <= this->_size && this->_size + 1 > this->_capacity) {
		MyVector temp(*this);
		if(_myptr != NULL) {
			delete[] _myptr;
		}
		_myptr = new int[this->_capacity * 2];
		memcpy(_myptr, temp._myptr, _capacity * 2 * sizeof(int));
		_myptr[n + 1] = _myptr[n];
		_myptr[n] = elem;	
		_size++;
		_capacity = _capacity * 2;
	} else {
		unsigned int i = this->_size;
		while(i > n) {
			_myptr[i] = _myptr[i - 1];
			i--;
		}
		_myptr[i] = elem;
		_size++;
	}
}

std::ostream& operator<< (std::ostream& os, const MyVector &print) {
	unsigned int n = print._size;	
	for(unsigned int i = 0; i != n; i++) {
		os << i << "->" << print._myptr[i] << std::endl;;
	}
	return os;	
}

void MyVector::push_back(int elem) {
	insert(_size, elem);
}
