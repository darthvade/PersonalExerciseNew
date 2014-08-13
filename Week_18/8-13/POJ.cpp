//POJ 2718

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int func(vector<int> &input) {

}

int main() {
	int n;
	while(cin >> n) {
		vector<int> input;
		string temp;
		getline(cin, temp);
		stringstream ins(temp);
		int itemp;
		while(ins >> itemp) {
			input.push_back(itemp);		
		}

	}
	return 0;
}
