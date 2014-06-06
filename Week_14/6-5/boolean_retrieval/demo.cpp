#include "BoolRe.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	vector<int> vec1 = {2, 4, 8, 16, 32, 64, 128};	
	vector<int> vec2 = {1, 2, 3, 5, 8, 13, 21, 34};	
	vector<int> result_and = BoolRe::Merge_And(vec1, vec2);
	for(auto i : result_and) {
		cout << i << ",";
	}
	cout << endl;
	vector<int> result_or = BoolRe::Merge_Or(vec1, vec2);
	for(auto i : result_or) {
		cout << i << ",";
	}
	cout << endl;
	vector<int> result_andnot = BoolRe::Merge_AndNot(vec1, vec2);
	for(auto i : result_andnot) {
		cout << i << ",";
	}
	cout << endl;
	return 0;
}
