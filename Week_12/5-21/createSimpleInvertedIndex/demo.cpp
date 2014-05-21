#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <utility>

using namespace std;

int main() {
	ifstream unicontent("/home/kevin/SpiderData/dmoz/UnipageTermContent.data"); //打开非重复网页文本库
	string strdocid; //文档编号
	string data; //文档文本数据
	map<string, set<pair<int, int> > > invertedindex; //存储倒排索引 <Term, <docID, TF> >
	//从非重复网页文本库中提取每个文档的文本分别建立倒排索引项
	while(getline(unicontent, strdocid)) {
		int docid = atoi(strdocid.c_str());
		getline(unicontent, data);
		if(data.length() == 0) { //忽略网页文本为空的网页
			continue;
		}	
		//统计每个网页中每个词项的词频TF
		istringstream strcontent(data);
		map<string, int> words_fre; //词项到词频的映射	
		string temp;
		while(strcontent >> temp) {
			++words_fre[temp];	
			strcontent.clear();
		}
		//生成到排索引
		map<string, int>::iterator mapiter = words_fre.begin();
		while(mapiter != words_fre.end()) {
			invertedindex[mapiter->first].insert(make_pair(docid, mapiter->second));
			++mapiter;	
		}

		unicontent.clear();
	}

	//将倒排索引写入文件
	ofstream invertedindexfile("/home/kevin/SpiderData/dmoz/invertedIndex.data");
	typedef map<string, set<pair<int, int> > >::iterator MapIter;
	typedef set<pair<int, int> >::iterator SetIter;
	MapIter mapiter = invertedindex.begin();
	while(mapiter != invertedindex.end()) {
		invertedindexfile << mapiter->first << "\t";	
		SetIter setiter = mapiter->second.begin();
		while(setiter != mapiter->second.end()) {
			invertedindexfile << setiter->first << "\t" << setiter->second << "\t"; 	
			++setiter;
		}
		invertedindexfile << endl;
		++mapiter;
	}
	invertedindexfile.close();

	return 0;
}
