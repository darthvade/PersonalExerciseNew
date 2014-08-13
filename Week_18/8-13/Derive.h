#ifndef __DERIVE__
#define __DERIVE__

#include "Base.h"

class Derive : public Base {
public:
	Derive() = default;
	Derive(std::string dr_name, int port, std::string bs_name) : 
		Base(port, bs_name), derive_name(dr_name) {}
	void print() {
			std::cout << "Derive:derive_name->" << derive_name << std::endl;	
	}
	virtual ~Derive() = default;
private:
	std::string derive_name;
};

#endif
