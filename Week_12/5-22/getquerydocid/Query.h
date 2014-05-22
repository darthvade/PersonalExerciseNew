/**
 *	基于倒排索引返回排好序的文档ID集合
 *	注：与查询词相关性越大的文档越排在前面
 */

#ifndef __QUERY_H__
#define __QUERY_H__

#include <unordered_map>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "./Jieba/MixSegment.hpp"

class Query {
public:
	explicit Query(const std::string, const std::string, const std::string);
	~Query();
	std::vector<int> queryOrderedDocids(const std::string); //输入查询词（文档）返回按相似度降序排列的文档ID
private:
	std::vector<double> getQueryTDIDF(std::vector<std::string> &);
	void _readInvertedFile(const std::string); //读取硬盘倒排索引文件到内存
	std::vector<int> _getQueryDocids(std::vector<std::string> &); //得到与查询词相关的文档集合
	std::vector<std::string> _getQueryTerms(const std::string); //得到查询文档分词后的词项集合（即真正的查询词集合，因为用户可能输入一句话）
	//内存数据结构
	std::unordered_map<std::string, std::map<int, double> > _invertedindex; //内存倒排索引
	CppJieba::MPSegment _seg; //分词器
	unsigned int _num_docs; //文档总数
};


#endif
