#include "MixSegment.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	const char * const TEST_FILE = "./output.txt";
    const char * const JIEBA_DICT_FILE = "./jieba.dict.utf8";
	const char * const HMM_DICT_FILE = "./hmm_model.utf8";
	CppJieba::MixSegment seg(JIEBA_DICT_FILE, HMM_DICT_FILE);
	vector<string> line_res;
	ifstream is(TEST_FILE);
	ofstream os("mission+++++++++++++++");
	string line;
	while(getline(is, line)) {
		seg.cut(line, line_res);		
		for(vector<string>::iterator iter = line_res.begin(); iter != line_res.end(); ++iter) {
			os << *iter << " ";
		}
		os << endl;
		line_res.clear();
		line.clear();
	}
	return 0;
}
