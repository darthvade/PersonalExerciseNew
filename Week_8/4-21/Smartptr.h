#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include "String.h"

class Smartptr {
public:
	Smartptr();
	Smartptr(String *);
	~Smartptr();

	void reset(String *);
	const String *getptr() const;

	String* operator->();
	const String* operator->() const;

	String& operator*();
	const String& operator*() const;
private:
	String *_ptr;

	Smartptr(const Smartptr&);
	Smartptr &operator=(const Smartptr&);
};


#endif
