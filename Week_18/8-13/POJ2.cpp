//POJ1007

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int func(string input) {
	int rat = 0;
	for(size_t i = 0; i < input.size(); ++i) {
		for(size_t j = i + 1; j < input.size(); ++j) {
			if(input[i] > input[j]) {
				rat++;
			}	
		}
	}
	return rat;
}

int main() {
	vector<string> input;
	vector<pair<int, int> > rating;
	int length, lines;
	cin >> length >> lines;
	size_t index = 0;
	while(lines--) {
		string temp;
		cin >> temp;
		input.push_back(temp);
		rating.push_back(make_pair(index++, func(temp)));
	}
	sort(rating.begin(), rating.end(), cmp);
	for(size_t i = 0; i < rating.size(); ++i) {
		cout << input[rating[i].first] << endl;	
	}
	return 0;
}
