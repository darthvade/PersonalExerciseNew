#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	fstream fs("./input.txt");	
	map<string, int> counter;
	string temp;
	while(fs >> temp) {
		++counter[temp];
	}
	for(map<string, int>::const_iterator iter = counter.begin(); iter != counter.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
	return 0;
}
