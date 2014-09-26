#include <iostream>
#include <vector>
#include <cstring>

template <unsigned N, unsigned M>
int cmpstr(const char (&a)[N], const char (&b)[M]) {
	return strcmp(a, b);
}

template <typename T>
int cmp(const T &a,const T &b) {
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

using namespace std;

int main() {
	cout << cmp(3, 2) << endl;
	cout << cmp(8, 2) << endl;
	vector<int> vec1 = {2, 4, 8};	
	vector<int> vec2 = {8, 2, 8};	
	cout << cmp(vec1, vec2) << endl;
	cout << strcmp("abc", "adg") << endl;
	return 0;
}
