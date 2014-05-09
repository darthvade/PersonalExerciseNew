
#include <iostream>

using namespace std;

class Integer {
public:
	//默认构造函数
	Integer() {
		_iptr = new int;	
		*_iptr = 0;
	}
	//显式构造函数
	Integer(const int i) {
		_iptr = new int(i);
	}
	//拷贝构造函数
	Integer(const Integer &i) {
		_iptr = i._iptr;
	}
	//复制运算符
	Integer& operator=(const Integer &i) {
		_iptr = i._iptr;	
		return *this;
	}
	//析构函数
	~Integer() {
		delete _iptr;
	}
	//debug
	void debug() {
		cout << *_iptr << endl;
	}
private:
	int *_iptr;
};

class U_ptr {
	friend class Smartpointer;
	int *ip;
	std::size_t counter;
	U_ptr(int *p) : ip(p), counter(1) {}
	~U_ptr() {
		delete ip;
	}
};

class Smartpointer {
public:
	Smartpointer(int *p) : ptr(new U_ptr(p)) {}
	Smartpointer(const Smartpointer & smpt) : ptr(smpt.ptr){
		smpt.ptr->counter++;
	}
	Smartpointer& operator=(const Smartpointer &smpt) {
		if(--ptr->counter == 0) {
			delete ptr;
		} 
	 	ptr = smpt.ptr;
		ptr->counter++;	
		return *this;
	}
	~Smartpointer() {
		if(--ptr->counter == 0) {
			delete ptr;
		}
	}
private:
	U_ptr *ptr;
//	int val; //做什么用？
};


int main() {
	/*
	Integer i1;
	i1.debug();
	Integer i2(99);
	i2.debug();
	i1 = i2;
	i1.debug();
	*/
	
	int *i = new int(99);
	Smartpointer smpt1 = Smartpointer(i);
	Smartpointer smpt2 = Smartpointer(smpt1);
	Smartpointer smpt3 = Smartpointer(smpt2);
	
	return 0;
}
