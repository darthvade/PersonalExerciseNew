/**
 * 检索最后一个网页会dump
 *
 */
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <boost/locale.hpp>
#include "./TextExtractor.h"
#include "./Jieba/MixSegment.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	const char * const JIEBA = "./dict/jieba.dict.utf8";
	const char * const HHM = "./dict/hmm_model.utf8";
	CppJieba::MixSegment seg(JIEBA, HHM);
	int index = atoi(argv[1]);
	ifstream pagelib("/home/kevin/SpiderData/dmoz/pagelib.data");
	ifstream pageindex("/home/kevin/SpiderData/dmoz/pageindex.index");
	ofstream outputpageContent("./outputpage.html");
	//读取索引文件到map
	int docid;
	int pos;
	map<int, int> indexmap;
	while(pageindex >> docid >> pos) {
		indexmap[docid] = pos;	
	}
	pageindex.close();
	pagelib.seekg(indexmap[index]);
	size_t length = indexmap[index + 1] - indexmap[index];
	char *buf = new char[length];
	pagelib.read(buf, length);
	pagelib.close();


	string result(buf);
	result = parseString(result, 127);//抽取正文

	//这一步之前必须判断字符的编码！
	result = boost::locale::conv::between(result, "UTF-8", "GBK");//正文的编码转换
	
	std::vector<string> segwords; //分词结果数组
	seg.cut(result,segwords); //分词
	//将结果写入文件
	typedef vector<string>::iterator Iter;
	for(Iter iter = segwords.begin(); iter != segwords.end(); ++iter) {
		if(iter->length() >= 2 && iter->length() < 20) {
			outputpageContent << *iter << endl;
		}		
	}
	
	outputpageContent << result;
	outputpageContent.close();

	delete[] buf;
	return 0;
}
