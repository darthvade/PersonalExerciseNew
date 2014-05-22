#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

struct termInfo {
	unsigned int docid; //文档编号
	unsigned int tf; //词项频率
	double weight; //词项权重
};

int main() {
	set<int> uniquedocid; //文档编号集合用于统计文档总数
	unordered_map<string, set<pair<int, int> > > invertedindex; //存储原始倒排索引
	unordered_map<string, vector<termInfo> > invertedindexwithweigth; //带词项权重的倒排索引
	ifstream invertedindexfile("/home/kevin/SpiderData/dmoz/invertedIndex.data"); //原始倒排文件

	//将倒排文件读入到内存
	string tempterm;
	while(getline(invertedindexfile, tempterm)) {
		stringstream strtempterm(tempterm);	
		string term;
		string docid;
		string tf;
		strtempterm >> term;
		while(strtempterm >> docid >> tf) {
			invertedindex[term].insert(make_pair(atoi(docid.c_str()), atoi(tf.c_str())));	
			uniquedocid.insert(atoi(docid.c_str())); 
			strtempterm.clear();
		}
		invertedindexfile.clear();
	}
	invertedindexfile.close();

	//计算文档权重
	typedef unordered_map<string, set<pair<int, int> > >::iterator Iter;
	Iter invertedindexiter = invertedindex.begin();
	while(invertedindexiter != invertedindex.end()) {
		double allweigth = 0;				
		typedef set<pair<int, int> >::iterator SetIter;
		//第一次遍历某一词项的所有文档信息计算weight
		SetIter setiter = invertedindexiter->second.begin();
		while(setiter != invertedindexiter->second.end()) {
			//计算TF * IDF
			double weight = setiter->second * (0.05 + log10(uniquedocid.size() / invertedindexiter->second.size()));
			termInfo insertterminfo;
			insertterminfo.weight = weight * weight;
			insertterminfo.docid = setiter->first;
			insertterminfo.tf = setiter->second;
			allweigth += weight;
			invertedindexwithweigth[invertedindexiter->first].push_back(insertterminfo); //向带有词项权重的倒排列表中插入词项信息
			++setiter;
		}
		//第二次遍历这一词项的所有全总信息，以完成权重的归一化（遍历词项在有权重倒排列表中的对应信息即可）
		vector<termInfo>::iterator setinfoiter = invertedindexwithweigth[invertedindexiter->first].begin();
		while(setinfoiter != invertedindexwithweigth[invertedindexiter->first].end()) {
			setinfoiter->weight /= sqrt(allweigth);	
			++setinfoiter;
		}

		++invertedindexiter;
	}

	
	//将带权重倒排索引写入文件
	ofstream Winvertedindexfile("/home/kevin/SpiderData/dmoz/invertedIndex_Weight.data");
	typedef unordered_map<string, vector<termInfo> >::iterator MapIter;
	typedef vector<termInfo>::iterator SetIter;
	MapIter mapiter = invertedindexwithweigth.begin();
	while(mapiter != invertedindexwithweigth.end()) {
		Winvertedindexfile << mapiter->first << "\t";	
		SetIter setiter = mapiter->second.begin();
		while(setiter != mapiter->second.end()) {
			//Winvertedindexfile << setiter->docid << "\t" << setiter->tf << "\t" << setiter->weight << '\t'; 	
			Winvertedindexfile << setiter->docid << "\t" << setiter->weight << '\t'; 	
			++setiter;
		}
		Winvertedindexfile << endl;
		++mapiter;
	}
	Winvertedindexfile.close();

	return 0;
}
