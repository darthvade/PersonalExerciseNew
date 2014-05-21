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

struct DocInfo {
	unsigned int docid; //文档编号
	string content; //文档内容
	bool flag; //文档是否以查重
};

int main() {
	ifstream content("/home/kevin/SpiderData/dmoz/pageTermContent.data");
	map<unsigned int, string> contentmap; //文档编号和文档内容（词项集合）的映射, 物理结构Map
	vector<DocInfo> contentvec; //文档编号和文档内容（词项集合）的映射, 物理结构Vector
	//读取文档内容到内存的contentvec
	string docid;
	string data;
	while(getline(content, docid)) {
		getline(content, data);	
		DocInfo insert;
		insert.docid = atoi(docid.c_str());
		insert.content = data;
		insert.flag = false;
		contentvec.push_back(insert);
		contentmap[atoi(docid.c_str())] = data;
		content.clear();
	}
	content.close();

	
	//生成非重复网页集
	std::set<int> uniquepage; //非重复网页集（文档编号表示）
	typedef vector<DocInfo>::iterator IterPage;
	IterPage iterpage = contentvec.begin();
	while(iterpage != contentvec.end()) {
		if(iterpage->flag == true) {
			++iterpage;
			continue;
		}
		std::set<int> tempset; //临时重复网页集（最后只需保留其中的一个到非重复网页集）
		IterPage inner = iterpage;
		while(inner != contentvec.end()) {
			if(inner->flag == true) {
				++inner;
				continue;
			}
			if(isSimilar(inner->content, iterpage->content)) {
				tempset.insert(inner->docid);	
				inner->flag = true;
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
