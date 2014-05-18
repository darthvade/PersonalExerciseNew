/**
 * 检索最后一个网页会dump
 *
 */
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	int index = atoi(argv[1]);
	ifstream pagelib("/home/kevin/SpiderData/dmoz/pagelib.data");
	ifstream pageindex("/home/kevin/SpiderData/dmoz/pageindex.index");
	ofstream outputpage("./outputpage.html");
	//读取索引文件到map
	int docid;
	int pos;
	map<int, int> indexmap;
	while(pageindex >> docid >> pos) {
		indexmap[docid] = pos;	
	}
	pageindex.close();
	pagelib.seekg(indexmap[index]);
	int length = indexmap[index + 1] - indexmap[index];
	char *buf = new char[length];
	pagelib.read(buf, length);
	pagelib.close();
	outputpage.write(buf, length);	
	outputpage.close();

	//测试写入一个字符串
	string result(buf);
	cout << result;

	delete[] buf;
	return 0;
}
