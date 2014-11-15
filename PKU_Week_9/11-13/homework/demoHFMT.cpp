#include "./HuffmanTree.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	cout << "Task[4]:" << endl;
	vector<int> kv = {5, 9, 11, 2, 7, 16};
	//vector<int> kv = {5, 9, 11, 2, 7, 16, 1000, 100000, 89, 876, 87, -213};
	HuffmanTree ht(kv);;
	ht.getHuffmanCode();
	for(auto i : kv) {
		cout << "[Key]:"<< i << "-->[Huffman Code]:" << ht[i]<< endl;
	}
	return 0;
}
