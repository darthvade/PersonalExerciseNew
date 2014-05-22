#include "Query.h"
#include "./Jieba/MixSegment.hpp"
#include <cstdlib>
#include <cmath>
#include <queue>
#include <utility>

struct Compare {
	bool operator() (const std::pair<int, double> &a, const std::pair<int, double> &b) {
		return a.second < b.second ? true : false;
	}
};

//求两个向量的余弦相似性
double getConsine(const std::vector<double> &a, const std::vector<double> &b) {
	//注：暂没有考虑向量不等长的情况
	auto itera = a.begin();
	auto iterb = b.begin();	
	double undera = 0;
	double underb = 0;
	double upper = 0;
	while(itera != a.end() && iterb != b.end()) {
		undera += (*itera) * (*itera);	
		underb += (*iterb) * (*iterb);	
		upper += (*itera) * (*iterb);
		++itera;
		++iterb;
	}
	return upper / sqrt(undera * underb);
}

std::vector<double> Query::getQueryTDIDF(std::vector<std::string> &queryterms) {
	double allwiegth = 0;
	std::vector<double> result;
	std::map<std::string, int> fre;
	//计算TD-IDF
	auto queryiter = queryterms.begin();
	while(queryiter != queryterms.end()) {
		++fre[*queryiter];
		++queryiter;
	}
	queryiter = queryterms.begin();
	while(queryiter != queryterms.end()) {
		double weight = 0;
		if(_invertedindex[*queryiter].size() != 0) {
			weight = fre[*queryiter] * log10(0.05 + _num_docs / _invertedindex[*queryiter].size());
		} else {
			weight = 1; //当查询词没有在文档中出现过	
		}
		allwiegth += weight * weight;
		result.push_back(weight);
		++queryiter;
	}
	//TD-iDF结果归一化处理
	auto resultiter = result.begin();
	while(resultiter != result.end()) {
		*resultiter /= allwiegth;
		++resultiter;
	}
	return result;
}

//得到两个有序数组的公共元素
std::vector<int> getCommon(std::vector<int> &a, std::vector<int> &b) {
	std::vector<int> result;
	auto itera = a.begin();
	auto iterb = b.begin();
	while(itera != a.end() && iterb != b.end()) {
		if(*itera == *iterb) {
			++itera;
			++iterb;
			result.push_back(*itera);
		} else {
			*itera > *iterb ? ++iterb : ++itera;	
		}
	}
	return result;
}

Query::Query(const std::string filename, const std::string dir1, const std::string dir2) :
_seg(dir1.c_str(), dir2.c_str())
{
	_readInvertedFile(filename);
}

Query::~Query() {

}

std::vector<int> Query::queryOrderedDocids(const std::string query) {
	std::vector<std::string> queryterms = _getQueryTerms(query); //查询词集合
	std::vector<int> initdocids = _getQueryDocids(queryterms); //待排序文档ID
	std::map<int, std::vector<double> > weigthvec; //文档ID和词项权重映射
	auto docidsiter = initdocids.begin();
	while(docidsiter != initdocids.end()) {
		auto termsiter = queryterms.begin();
		while(termsiter != queryterms.end()) {
			weigthvec[*docidsiter].push_back(_invertedindex[*termsiter][*docidsiter]);	
			++termsiter;
		}
		++docidsiter;
	}	
	std::vector<double> queryweight = getQueryTDIDF(queryterms);
	std::priority_queue<int, std::vector<std::pair<int, double> >, Compare> score; //文档相似度得分
	auto mapiter = weigthvec.begin();
	while(mapiter != weigthvec.end()) {
		double tempscore = getConsine(queryweight, mapiter->second);
		score.push(std::make_pair(mapiter->first, tempscore));	
		++mapiter;
	}
	std::vector<int> result;
	while(!score.empty()) {
		result.push_back(score.top().first);
		score.pop();
	}
	return result;
} //输入查询词（文档）返回按相似度降序排列的文档ID

void Query::_readInvertedFile(const std::string filename) {
	//计算文档总数
	std::set<int> count_num_docs;
	//读文件
	std::ifstream indexfile(filename);	
	std::string docinfo;
	while(getline(indexfile, docinfo)) {
		std::stringstream tempdocinfo(docinfo);	
		std::string term;
		std::string docid;
		std::string weight;
		tempdocinfo >> term;
		while(tempdocinfo >> docid >> weight) {
			_invertedindex[term][atoi(docid.c_str())] = atof(weight.c_str());
			count_num_docs.insert(atoi(docid.c_str()));
		}
	}
	_num_docs = count_num_docs.size();
} //读取硬盘倒排索引文件到内存

std::vector<int> Query::_getQueryDocids(std::vector<std::string> &queryterms) {
	//将查询词对应的所有文档ID找到
	std::vector<std::vector<int> > queryvec;
	auto queryiter = queryterms.begin();
	while(queryiter != queryterms.end()) {
		auto mapiter = _invertedindex[*queryiter].begin();
		std::vector<int> temp;
		while(mapiter != _invertedindex[*queryiter].end()) {
			temp.push_back(mapiter->first);
			++mapiter;
		}
		++queryiter;
		queryvec.push_back(temp);
	}
	//计算查询词对应的公共文档ID
	auto veciter = queryvec.begin();
	std::vector<int> last = *veciter;
	while(veciter != (queryvec.end() - 1)) {
		last = getCommon(last, *(veciter + 1));		
		++veciter;
	}
	return last;
} //得到与查询词相关的文档集合

std::vector<std::string> Query::_getQueryTerms(const std::string query) {
	std::vector<std::string> result;
	_seg.cut(query, result);
	return result;
} //得到查询文档分词后的词项集合（即真正的查询词集合，因为用户可能输入一句话）

