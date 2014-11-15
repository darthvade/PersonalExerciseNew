#include <queue>
#include <iostream>
#include <vector>
#include "./BinarySearchTree.h"

using namespace std;

int main() {
	cout << "Task[1]:" << endl;
	vector<int> initv = {12, 12, 8, 17, 11, 16, 2, 13, 9, 21, 4, -78, 129, 0, 0, 23};	
	queue<int> initq;
	for(auto i : initv) {
		initq.push(i);
	}
	BinarySearchTree<int> bst(initq);
	cout << "leaves count = " << bst.getNumLeaves() << endl;
	cout << "sum value = " << bst.getSumValueLeaves() << endl;
	return 0;
}



