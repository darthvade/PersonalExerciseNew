#include "Query.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	Query q("/home/kevin/SpiderData/dmoz/invertedIndex_Weight.data", "./dict/jieba.dict.utf8", "./dict/hmm_model.utf8");
	cout << "init success!" << endl;
	while(true) {	
		string query;
		cin >> query;
		vector<int> result = q.queryOrderedDocids(query);
		auto iter = result.begin();
		int i = 1;
		cout << result.size()  << endl;	
		while(iter != result.end()) {
			cout << *iter << "\t" << i++ << endl;	
			++iter;
		}
	}
	return 0;
}
