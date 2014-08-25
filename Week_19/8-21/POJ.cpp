//POJ-1330

#include <iostream>
#include <cstring>

using namespace std;

int tree[10000];

int depth(int node) {
	int dep = 0;
	while(tree[node]) {
		node = tree[node];
		++dep;
	}
	return dep;
}

void goback(int &node, int gap) {
	while(gap--) {
		node = tree[node];	
	}
}

int findcomm(int nodeA, int nodeB) {
	while(nodeA != nodeB && tree[nodeA] && tree[nodeB]) {
		nodeA = tree[nodeA];
		nodeB = tree[nodeB];
	}
	return nodeA;
}

int main() {
	memset(tree, 0, 10000 * sizeof(int));
	int ncase;
	cin >> ncase;
	while(ncase--) {
		int nnode;
		cin >> nnode;
		while(nnode-- != 1) {
			int node;
			int pnode;
			cin >> pnode >> node;
			tree[node] = pnode;	
		}
		int nodeA;
		int nodeB;
		cin >> nodeA >> nodeB;
		int gap_depth = depth(nodeA) - depth(nodeB);
		if(gap_depth > 0) {
			goback(nodeA, gap_depth);	
		} else if (gap_depth < 0) {
			goback(nodeB, -gap_depth);	
		} 
		cout << findcomm(nodeA, nodeB) << endl;	
		memset(tree, 0, 10000 * sizeof(int));
	}
	return 0;
}
