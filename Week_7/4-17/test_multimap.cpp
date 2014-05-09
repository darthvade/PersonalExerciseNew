#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main() {

	multimap<string, string> mp;
	mp.insert(make_pair(string("aaa"), string("hehe1")));
	mp.insert(make_pair(string("aaa"), string("hehe2")));
	mp.insert(make_pair(string("aaa"), string("hehe3")));

	mp.insert(make_pair(string("bbb"), string("hello4")));

	mp.insert(make_pair(string("aaa"), string("hehe4")));
	mp.insert(make_pair(string("aaa"), string("hehe5")));

	
	mp.insert(make_pair(string("bbb"), string("hello1")));
	mp.insert(make_pair(string("bbb"), string("hello2")));
	mp.insert(make_pair(string("bbb"), string("hello3")));

	for(multimap<string, string>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
		cout << iter->first << " " << iter->second <<  endl; 
	}

	cout << "-----------------" << endl;

	cout << mp.count("bbb") << endl;;
	multimap<string, string>::iterator it = mp.find("bbb");
	cout << it->first << " " << it->second <<  endl; 

	cout << "-----------------" << endl;

	multimap<string, string>::iterator itlow = mp.lower_bound("bbb");
	multimap<string, string>::iterator ithigh = mp.upper_bound("bbb");

	for(multimap<string, string>::iterator iter = itlow; iter != ithigh; ++iter) {
		cout << iter->first << " " << iter->second <<  endl; 
	}

	cout << "-----------------" << endl;

	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> low_high;

	low_high = mp.equal_range("aaa");

	for(multimap<string, string>::iterator iter = low_high.first; iter != low_high.second; ++iter) {
		cout << iter->first << " " << iter->second <<  endl; 
	}

	return 0;
}
