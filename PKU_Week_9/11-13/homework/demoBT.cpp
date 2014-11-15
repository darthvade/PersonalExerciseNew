#include "./BinaryTree.h"
#include <iostream>


int main() {
	std::cout << "Task[3]:" << std::endl;
	std::vector<int> initv{3, 4, 56, 67, 34, 23, 14, 67, 43, 0 ,99};
	std::queue<int> initq;
	for(auto i : initv) {
		initq.push(i);
	}
	BinaryTree<int> bt2(initq, 0);
	bt2.printPreorderTrverse();
	std::cout << std::endl;
	std::cout << "parents value: " << bt2.getParentsValue(99) << std::endl;
	return 0;
}
