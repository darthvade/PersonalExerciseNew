#include <iostream>
#include <vector>

using std::vector;

struct BTree {
	int data;
	struct BTree *left;
	struct BTree *right;
};

void swap(struct BTree *********a, struct BTree *********b) {
	struct BTree ********temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int * &a, int * &b) {
	int *temp;
	temp = a;
	a = b;
	b = temp;
}

bool input_word(std::size_t number, std::vector<std::string> &vec) {
	if(number < 1) {
		return false;
	}
	std::string temp;
	while(number--) {
		std::cin >> temp;
		vec.push_back(temp);	
	}
	return true;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << std::endl;	
	}
	int a = 1;
	int b = 2;
	int *pa = &a;
	int *pb = &b;
	std::cout << *pa << " " << *pb << std::endl;
	swap2(pa, pb);
	std::cout << *pa << " " << *pb << std::endl;
	vector<std::string> vec;
	input_word((std::size_t)3, vec);
	for(vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		std::cout << *iter << std::endl;	
	}
	return 0;
}
