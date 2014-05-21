#ifndef __FUNC__
#define __FUNC__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <queue>
#include <set>
#include <cmath>

class Compare {
public:
	bool operator() (std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
		return a.second < b.second ? true : false; //频率越大越接近堆顶	
	}
};

std::vector<std::string> getTopNwords(std::string &str, int n) {
	std::vector<std::string> result;
	std::map<std::string, int> fre; //存储单词及其词频
	std::priority_queue<std::pair<std::string, int> , std::vector<std::pair<std::string, int> > , Compare> topn; //按词频高低将序排列
	//结算单词词频
	std::istringstream inputstr(str);	
	std::string temp;
	while(inputstr >> temp) {
		++fre[temp];
	}
	//将所有单词依词频放入优先级队列排序
	typedef std::map<std::string, int>::iterator MapIter;
	MapIter mapiter = fre.begin();
	while(mapiter != fre.end()) {
		topn.push(make_pair(mapiter->first, mapiter->second));
		++mapiter;
	}
	//取出TopN放入结果数组 如果单词总数没有N则取所有
	while(n-- && !topn.empty()) {
		result.push_back(topn.top().first);
		//std::cout << topn.top().second << std::endl; //DEBUG
		topn.pop();
	}
	return result;
}

bool isSimilar(std::string &stra, std::string &strb) {
	//总的长度相差太大很有可能不相似
	int dislen = abs(stra.length() - strb.length());	
	if(dislen > 128) {
		return false;
	}
	typedef std::vector<std::string>::iterator Iter;
	//注：topa和topb的长度未必都是10
	std::vector<std::string> topa = getTopNwords(stra, 10);
	std::vector<std::string> topb = getTopNwords(strb, 10);
	//空字符集和任何字符集相似，因为我们要去掉空字符集（即没有内容的网页）
	if(topa.empty() || topb.empty()) {
		return true;
	}
	unsigned int counter = 0;
	std::set<std::string> unique;
	Iter itera = topa.begin();
	while(itera != topa.end()) {
		unique.insert(*itera);
		++itera;
	}
	Iter iterb = topb.begin();
	while(iterb != topb.end()) {
		if(unique.count(*iterb)) {
			++counter;	
		}
		++iterb;
	}
	return counter > 7 ? true : false;	
}


int getValPage(std::set<int> &pageset, std::map<unsigned int, std::string> &content) {
	//暂时的算法是选取内容长度最大者		
	std::set<int>::iterator iter = pageset.begin();
	int select = *iter;
	while(iter != pageset.end()) {
		if(content[*iter].length() > content[select].length()) {
			select = *iter;	
		}
		++iter;
	}
	return select;
}

#endif
