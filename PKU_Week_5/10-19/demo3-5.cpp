#include <iostream>
#include <vector>
using namespace std;

int main() {
	int score;
	vector<int> input;
	while(cin >> score) {
		input.push_back(score);
	}
	for(unsigned int n = 0; n < 11; ++n) {
		unsigned int m = 0;
		for(auto i = input.begin(); i != input.end(); ++i) {
			if(*i/ 10 == n) {
				m++;
			}
		}	
		cout << m;
	}
	return 0;
}
