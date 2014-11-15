#include "./CompleteBinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout << "Task[2]:" << endl;
	vector<int> initv = {3, 4, 56, 67, 34, 23, 14, 67, 43};
	for(std::size_t i = 0; i != initv.size(); ++i) {
		cout << "[Index " << i + 1 << "]-->" << initv[i] << endl;
	}
	CompleteBinaryTree<int> cbt(initv);
	cbt.printParentsChildren(3);
	return 0;
}
