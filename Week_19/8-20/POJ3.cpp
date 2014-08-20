// POJ-2418

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string temp;
	map<string, unsigned int> counter;
	int n = 0;
	while(getline(cin, temp)) {
		++counter[temp];	
		++n;
	}
 	map<string, unsigned int>::iterator iter = counter.begin();
	while(iter != counter.end()) {
		printf("%s %.4lf\n", iter->first.c_str(), iter->second * 100.0 / n);	
		++iter;
	}	
	return 0;
}
