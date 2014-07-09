#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void myfunction(vector<string> &input) {
	for_each(input.begin(), input.end(), [](const string &a){cout << a << endl;});
}

int main() {
	vector<string> hehe = {"a", "b", "c", "d"};	
	myfunction(hehe);
	return 0;
}
