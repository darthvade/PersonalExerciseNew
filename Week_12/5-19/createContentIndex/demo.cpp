/**
 * 检索最后一个网页会dump
 *
 */
#include <utility>
#include <set>
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

bool isUtf_8(const char* str,long length) {
	int i;
	int nBytes=0;//UFT8可用1-6个字节编码,ASCII用一个字节 
	unsigned char chr; 
	bool bAllAscii=true; //如果全部都是ASCII, 说明不是UTF-8  
	for(i=0;i<length;i++) {
		chr= *(str+i); 
		if( (chr&0x80) != 0 ) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx 
			bAllAscii= false;  
		if(nBytes==0) //如果不是ASCII码,应该是多字节符,计算字节数
		{
			if(chr>=0x80) 
			{
				if(chr>=0xFC&&chr<=0xFD)
					nBytes=6;
				else if(chr>=0xF8)  
					nBytes=5;
				else if(chr>=0xF0)  
					nBytes=4;  
				else if(chr>=0xE0) 
					nBytes=3; 
				else if(chr>=0xC0) 
					nBytes=2; 
				else 
				{
					return false;
				}	
				nBytes--;  
			}		
		}
		else //多字节符的非首字节,应为 10xxxxxx 
		{
			if( (chr&0xC0) != 0x80 ) 
			{
				 return false; 
			}
			nBytes--;
		}
	}
	if( nBytes > 0 ) //违返规则
	{
		return false;
	}
	if( bAllAscii ) //如果全部都是ASCII, 说明不是UTF-8 
	{
		return false;
	}
	return true;
}

int main() {
	const char * const JIEBA = "./dict/jieba.dict.utf8";
	const char * const HHM = "./dict/hmm_model.utf8";
	CppJieba::MixSegment seg(JIEBA, HHM);
	ifstream pagelib("/home/kevin/SpiderData/dmoz/pagelib.data");
	ifstream pageindex("/home/kevin/SpiderData/dmoz/pageindex.index");
	ofstream outputpageContent("/home/kevin/SpiderData/dmoz/pageTermContent.data", std::ofstream::app);
	//读取停用词集
	ifstream stopwordsfile("/home/kevin/Github_practice/Week_11/5-18/getHtmlContentfromindex/dict/stop_words.utf8");	
	set<string> stopwords;
	string temp;
	while(stopwordsfile >> temp) {
		stopwords.insert(temp);	
	}
	stopwordsfile.close();

	//读取索引文件到vector
	unsigned int docid;
	unsigned long long int pos;
	vector<pair<unsigned int, unsigned long long int> > indexvec;
	while(pageindex >> docid >> pos) {
		indexvec.push_back(make_pair(docid, pos));
	}
	pageindex.close();

	//遍历原始网页库以建立网页文本库
	for(unsigned int index = 0; index != indexvec.size() - 1; index++) {
		//读取原始网页文件
		pagelib.seekg(indexvec[index].second);
		size_t length = indexvec[index + 1].second - indexvec[index].second;
		char *buf = new char[length];
		pagelib.read(buf, length);

		string result(buf);
		result = parseString(result, 20);//抽取正文 最后一个参数为抽取阈值，越大抽取越严格！
		if(result.empty()) {
			continue;
		}

		//这一步之前必须判断字符的编码！
		if(!isUtf_8(result.c_str(), result.length())) {
			result = boost::locale::conv::between(result, "UTF-8", "GBK");//正文的编码转换
		}

		std::vector<string> segwords; //分词结果数组
		seg.cut(result,segwords); //分词

		//将结果写入文件
		outputpageContent << indexvec[index].first << endl; //写入文档编号
		if(!segwords.empty()) {
			typedef vector<string>::iterator Iter;
			for(Iter iter = segwords.begin(); iter != segwords.end(); ++iter) {
				if(iter->length() >= 2 && iter->length() < 20 && !stopwords.count(*iter)) { //is vital to check the length!
					outputpageContent << *iter << ' ';
				}		
			}
			outputpageContent << endl;
		} else {
			outputpageContent << endl;
		}
		delete[] buf;
	} 

	outputpageContent.close();
	return 0;
}
