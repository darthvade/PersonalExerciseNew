#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	
	vector<int> vect;
	for(vector<int>::size_type ix = 0; ix != 10; ++ix) {
		vect.push_back(ix);
		vect.push_back(ix);
	}
	set<int> myset(vect.begin(), vect.end());
	cout << "vect " << vect.size() << endl;  
	cout << "myset " << myset.size() << endl;  

	return 0;
}
