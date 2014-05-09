#include <iostream>
#include <fstream>
#include <map>
#include <utility>

using namespace std;

int main() {
	fstream fs("./input.txt");	
	map<string, int> counter;
	string temp;
	while(fs >> temp) {
		pair<map<string, int>::iterator , bool> ret = counter.insert(make_pair(temp, 1));
		if(!ret.second) {
			++ret.first->second;
		}
	}
	for(map<string, int>::const_iterator iter = counter.begin(); iter != counter.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
	cout << counter.count("aaa") << endl;
	map<string, int>::iterator iter2 = counter.find("aaa");
	cout << iter2->first << " " << iter2->second << endl;
	return 0;
}
