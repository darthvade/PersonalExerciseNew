#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {

	map<string, string> mp;

	fstream fs("./code.txt");
	string left, right;
	while(fs >> left >> right) {
		mp.insert(make_pair(left, right));	
	}
	fs.close();
	fs.clear();

	fstream fs2("./input.txt");
	fstream fs3;
	fs3.open("./output", fstream::out);
	string line;
	while(getline(fs2, line)) {
		istringstream is(line);		
		string word;
		while(is >> word) {
			map<string, string>::iterator rent = mp.find(word);	
			if(rent != mp.end()) {
				fs3 << rent->second;	
				fs3 << " ";
				fs3.flush();
			}
		}
		fs3 << endl;
	}
	fs2.close();
	fs2.clear();
	fs3.close();
	fs3.clear();

	cout << "hehe" << endl;
	return 0;
}
