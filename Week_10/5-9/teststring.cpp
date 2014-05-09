#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
	
	unordered_map<string, string> cache;
	cache.insert({"你", "你们"});
	cache.insert({"你1", "你们1"});
	cache.insert({"你2", "你们2"});
	for(unordered_map<string, string>::iterator iter = cache.begin(); iter != cache.end(); ++iter) {
		cout << (*iter).first <<  " --> " << (*iter).second << endl;	
	}
	return 0;
}
