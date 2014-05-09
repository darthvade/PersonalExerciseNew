#include <iostream>
#include <stdexcept>

int main() {

	try{
		throw std::runtime_error("hehe ?!");	
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

}
