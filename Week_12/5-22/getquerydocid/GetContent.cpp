#include "GetContent.h"

GetContent::GetContent(const std::string filename) {
	readContentFile(filename);
}

GetContent::~GetContent() {

}

void GetContent::readContentFile(const std::string filename) {
	std::ifstream input(filename);	
	std::string docid;
	std::string content;
	while(getline(input, docid)) {
		getline(input, content);
		_content[atoi(docid.c_str())] = content;
		input.clear();
	}
}

std::string GetContent::getTitle(unsigned int docid) {
	return _content[docid].substr(0, 30);
} //返回对应文档的标题

std::string GetContent::getSummary(unsigned int docid) {
	return _content[docid].substr(0, 300) + "...";
} //返回对应文档ID的摘要

std::string GetContent::getResult(std::vector<int> resvec) {
	Json::Value root;
	Json::Value arr;
	auto iter = resvec.begin();
	while(iter != resvec.end()) {
		Json::Value elem;
		elem["title"]  = getTitle(*iter);
		elem["summary"] = getSummary(*iter);
		arr.append(elem);
		++iter;
	}
	root["files"] = arr;
	Json::StyledWriter writer;
	return writer.write(root);
}
