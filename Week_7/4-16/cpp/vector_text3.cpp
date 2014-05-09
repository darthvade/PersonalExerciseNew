#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		cout << *iter <<  endl;	
	}

	vec.insert(vec.begin() + 2, 999);

	cout << endl;
	for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		cout << *iter <<  endl;	
	}

	return 0;
}
