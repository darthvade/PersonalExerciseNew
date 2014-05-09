#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
	/*
	 *
	 * wstring 不能放入unordered_map
	 *
	 */	
	unordered_map<wstring, wstring> cache;
	cache.insert({L"你", L"你们"});
	cache.insert({L"你1", L"你们1"});
	cache.insert({L"你2", L"你们2"});
	for(unordered_map<wstring, wstring>::iterator iter = cache.begin(); iter != cache.end(); ++iter) {
		wcout << (*iter).first <<  L" --> " << (*iter).second << endl;	
	}
	return 0;
}
