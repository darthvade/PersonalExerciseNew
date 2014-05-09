#include <iostream>
#include <vector>

int main() {

	/*
	int **arr = new int *[4];
	for(int i = 0; i != 4; ++i) {
		arr[i] = new int[5];
	}
	*/
	std::vector<int> vec;
	//std::vector<int>::size_type i = 0;	
	//int (*a[10])(int);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for(std::vector<int>::size_type i = vec.size() - 1; i >= 0; --i) {
	
	}
	return 0;
}
