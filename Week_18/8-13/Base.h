#ifndef __BASE__
#define __BASE__

#include <string>
#include <iostream>

class Base {
public:
	Base() = default;
	Base(int port, std::string bs_name) :
		port(port), base_name(bs_name) {}
	virtual void print() {
			std::cout << "Base:base_name->" << base_name << std::endl;	
	}
	virtual ~Base() = default;
protected:
	int port;
private:
	std::string base_name;
};

#endif

