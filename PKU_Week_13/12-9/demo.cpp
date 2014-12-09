#include "./MySort.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec{2, 4, 5, 8, 1, 9, 23, 45, 2};
	MySort::BubbleSort(vec, "INC");
	for(auto i : vec) {
		cout << i << endl;
	}
	return 0;
}
