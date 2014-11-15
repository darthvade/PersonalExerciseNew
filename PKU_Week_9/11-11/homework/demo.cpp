#include "./BinaryTree.h"
#include <iostream>


int main() {
	std::vector<char> inv{'-', '+', '*', '*', 'c', 'a', '+', 'a', 'b', '#', '#', '#', '#', 'b', 'c'};
	std::queue<char> inq;
	for(auto i : inv) {
		inq.push(i);
	}
	BinaryTree<char> bt(inq, '#');
	bt.printPreorderTrverse();
	std::cout << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;
	bt.printInorderExp();
	return 0;
}
