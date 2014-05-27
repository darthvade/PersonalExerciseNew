#ifndef __GETCONTENT_H__
#define __GETCONTENT_H__

#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "./json/json.h"

class GetContent {
public:
	GetContent(const std::string);
	~GetContent();
	std::string getResult(std::vector<int>); //返回Json格式字符串
private:
	void readContentFile(const std::string); //读取网页文本到内存
	std::string getTitle(unsigned int); //返回对应文档ID的标题
	std::string getSummary(unsigned int); //返回对应文档ID的摘要
	std::unordered_map<unsigned int, std::string> _content; //网页文本内容
};

#endif
