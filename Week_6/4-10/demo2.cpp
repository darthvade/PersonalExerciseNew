#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int main() {

	vector<string> vec;
	vector<string> vec3;

	std::ifstream is;
	is.open("./xxoo.txt");

	string temp;
	while(getline(is, temp)) {
		std::istringstream ss(temp);
		string temp2;
		while(ss >> temp2) {
			vec3.push_back(temp2);
		}
		vec.push_back(temp);
	}

	cout << "strings" << endl << endl;

	for(vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << endl;
	}

	cout << "words" << endl << endl;

	for(vector<string>::iterator iter = vec3.begin(); iter != vec3.end(); iter++) {
		cout << *iter << endl;
	}

	is.close();
	is.clear();
/*
	cout << "  next    " << endl;

	string s = "  hehe   klk   klk l";
	std::istringstream ss(s);
	vector<string> vec2;
	while(ss >> temp) {
		vec2.push_back(temp);
	}
	for(vector<string>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) {
		cout << *iter << endl;
	}
*/
	return 0;
}
