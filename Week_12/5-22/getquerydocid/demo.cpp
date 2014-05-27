#include "Query.h"
#include "GetContent.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	Query q("/home/kevin/SpiderData/dmoz/invertedIndex_Weight.data", "./dict/jieba.dict.utf8", "./dict/hmm_model.utf8");
	GetContent get("/home/kevin/SpiderData/dmoz/pageTermContent.data");
	cout << "init success!" << endl;
	while(true) {	
		string query;
		cin >> query;
		vector<int> result = q.queryOrderedDocids(query);
		cout << get.getResult(result) << endl;
	}
	return 0;
}
