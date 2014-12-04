#include <iostream>
#include <vector>

using namespace std;

bool cmpvec(vector<int> &va, vector<int> &vb) {
	if(va.size() > vb.size()) {
		return false;
	}
	auto pa = va.begin();
	auto pb = vb.begin();
	while(pa != va.end()) {
		if(*pa != *pb) {
			break;
		}	
		++pa;
		++pb;
	}
	if(pa == va.end()) {
		return true;
	} else {
		return false;
	}
}

int main() {
	vector<int> vec1 = {0, 1, 1, 2};
	vector<int> vec2 = {0, 1, 1, 2, 3, 5, 8};
	if(vec1.size() < vec2.size()) {
		cout << cmpvec(vec1, vec2) << endl;	
	} else {
		cout << cmpvec(vec2, vec1) << endl;	
	}
	return 0;
}
