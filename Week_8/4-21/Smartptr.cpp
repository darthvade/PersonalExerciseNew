#include "Smartptr.h"

#include <iostream>

using namespace std;

Smartptr::Smartptr() : _ptr(NULL){

}

Smartptr::Smartptr(String *p) : _ptr(p) {
	cout << "smartptr constractor!" << endl;
}

Smartptr::~Smartptr() {
	cout << "smartptr destractor!" << endl;
	delete _ptr;
}

void Smartptr::reset(String *p) {
	if(p != _ptr) {
		delete _ptr;
		_ptr = p;
	}	
}

String* Smartptr::operator->() {
	return _ptr;
}

const String* Smartptr::operator->() const{
	return _ptr;
}

String& Smartptr::operator*() {
	return *_ptr;
}

const String& Smartptr::operator*() const{
	return *_ptr;
}
