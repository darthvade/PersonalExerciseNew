#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <iostream>

class MyVector {
	friend std::ostream& operator<< (std::ostream&, const MyVector &);
public:
	MyVector();
	MyVector(int n);
	MyVector(int *, int *);
	~MyVector();
	MyVector(const MyVector&);
	MyVector& operator= (const MyVector&);
	bool operator!= (const MyVector&) const;
	int& operator[] (const unsigned int index);
	unsigned int size();
	unsigned int capacity();
	void insert(unsigned int, int);
	void push_back(int);
private:
	int *_myptr;
	unsigned int _size;
	unsigned int _capacity;
};


#endif
