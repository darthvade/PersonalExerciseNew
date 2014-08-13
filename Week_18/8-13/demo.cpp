#include "./Base.h"
#include "./Derive.h"

void static_print(Base &b) {
	b.print();
}

int main() {
	Base base(1024, "I'm base!");
	Derive der("base_name", 8848, "I'm derive!");
	static_print(der);
	return 0;
}
