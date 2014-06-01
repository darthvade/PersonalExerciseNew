#include "./Jieba/MixSegment.hpp"
#include "TextExtractor.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

	const char * const JIEBA = "./dict/jieba.dict.utf8";
	const char * const HHM = "./dict/hmm_model.utf8";
	CppJieba::MixSegment seg(JIEBA, HHM);

	//读取需处理文本
	ifstream io("./input");
	string input;
	string temp;
	while(io >> temp) {
		input.append(temp);
		io.clear();
		temp.erase();
	}
	io.close();
	
	//html去标签
	string result = input;
	assign_regex();	
	removeTags(result);
	removeSpace(result);

	//分词
	vector<string> segwords;
	seg.cut(result, segwords);	

	//读取停用词集
	ifstream stopwordsfile("./dict/stop_words.utf8");	
	set<string> stopwords;
	string temp2;
	while(stopwordsfile >> temp2) {
		stopwords.insert(temp2);	
		stopwordsfile.clear();
		temp2.erase();
	}
	stopwordsfile.close();

	//生成结果
	result.erase();
	auto iter = segwords.begin();
	while(iter != segwords.end()) {
		if(!stopwords.count(*iter)) {
			result.append(*iter).append("\t");
		}
		++iter;
	}


	//结果输出
	ofstream oo("./output");
	oo << result;	
	oo.close();

	return 0;
}
