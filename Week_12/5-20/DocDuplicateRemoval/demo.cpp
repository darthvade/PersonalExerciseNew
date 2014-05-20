#include <utility>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <set>
#include "function.hpp"

using namespace std;


int main() {
	ifstream content("/home/kevin/SpiderData/dmoz/pageTermContent.data");
	map<unsigned int, string> contentmap; //文档编号和文档内容（词项集合）的映射, 物理结构Map
	vector<pair<unsigned int, string> > contentvec; //文档编号和文档内容（词项集合）的映射, 物理结构Vector
	//读取文档内容到内存的contentvec
	string docid;
	string data;
	while(getline(content, docid)) {
		getline(content, data);	
		contentvec.push_back(make_pair(atoi(docid.c_str()), data));
		contentmap[atoi(docid.c_str())] = data;
		content.clear();
	}
	content.close();

	
	//生成非重复网页集
	std::set<int> uniquepage; //非重复网页集（文档编号表示）
	typedef vector<pair<unsigned int, string> >::iterator IterPage;
	IterPage iterpage = contentvec.begin();
	while(iterpage != contentvec.end()) {
		std::set<int> tempset; //临时重复网页集（最后只需保留其中的一个到非重复网页集）
		IterPage inner = iterpage;
		while(inner != contentvec.end()) {
			if(isSimilar(inner->second, iterpage->second)) {
				tempset.insert(inner->first);	
			}	
			++inner;
		}
		int unipage = getValPage(tempset, contentmap); //在重复网页中找到最有价值的一个
		cout << tempset.size() << endl; //DEBUG
		cout << unipage << endl; //DEBUG
		uniquepage.insert(unipage);
		++iterpage;
	}

	//生成非重复网页文本库	
	ofstream uniquecontent("/home/kevin/SpiderData/dmoz/UnipageTermContent.data");	
	std::set<int>::iterator uniiter = uniquepage.begin();	
	while(uniiter != uniquepage.end()) {
		uniquecontent << *uniiter << endl;
		uniquecontent << contentmap[*uniiter] << endl;
		++uniiter;
	}
	uniquecontent.close();
	
	return 0;
}
