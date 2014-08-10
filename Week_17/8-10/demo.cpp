#include <vector>
#include <iostream>

int main() {
	std::vector<int *> vecp;
	int *p1 = new int(100);
	int *p2 = new int(250);
	int *p3 = new int(350);
	vecp.push_back(p1);
	vecp.push_back(p2);
	vecp.push_back(p3);
	for(auto p : vecp) {
		std::cout << *p << std::endl;
	}
	return 0;
}
