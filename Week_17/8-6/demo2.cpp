#include <iostream>
#include <string>
#include <memory>

//behave like Class
class HasPtr {
	public:
		HasPtr(const std::string &str = std::string()) :
			p(new std::string(str)), num(0) {}
		HasPtr(const HasPtr &hp) :
			p(new std::string(*hp.p)), num(hp.num) {
		}
		HasPtr& operator=(const HasPtr &hp) {
			auto ptr = new std::string(*hp.p);	
			delete p;
			num = hp.num;
			p = ptr;
			return *this;
		} 
		~HasPtr() {
			delete p;
		}
	#ifdef DEBUG
		void print() {
			std::cout << "Addr-> " << p << ", Value-> " << *p << std::endl;
		}
	#endif
	private:
		std::string *p;
		int num;
};

//behave like Pointer (reference counter)
class NewHasPtr {
	public:
		NewHasPtr(const std::string &s = std::string()) :
			p(new std::string(s)), num(0), counter(new std::size_t(1)) {}
		NewHasPtr(const NewHasPtr &nhp) {
			p = nhp.p;
			(*nhp.counter)++;
			counter = nhp.counter;	
			num = nhp.num;
		}
		NewHasPtr& operator=(const NewHasPtr &nhp) {
			++(*nhp.counter);
			if(--(*counter) == 0) {
				delete counter;
				delete p;
			}	
			p = nhp.p;
			num = nhp.num;
			counter = nhp.counter;
			return *this;
		}
		~NewHasPtr() {
			if(--(*counter) == 0) {
				delete counter;
				delete p;
			}
		}
	#ifdef DEBUG
		void print() {
			std::cout << "Addr-> " << p << ", Value-> " << *p << ", Counter-> " << *counter << std::endl;
		}
	#endif
	private:
		std::string *p;
		int num;
		std::size_t *counter;
};

int main() {
	HasPtr p1("Hello World!");
	HasPtr p2("wtf!");
	p1.print();
	p2.print();
	p1 = p2;
	p1.print();
	p2.print();
//	auto ptr = std::make_shared<HasPtr>(p1);
//	auto ptr2 = ptr;
//	ptr2->print();
//	std::cout << ptr.use_count() << std::endl;
	NewHasPtr newp1("newp1");
	NewHasPtr newp2(newp1);
	NewHasPtr newp3(newp2);
	NewHasPtr newp4 = newp2;
	newp1.print();
	newp2.print();
	newp3.print();
	newp4.print();
	return 0;
}
