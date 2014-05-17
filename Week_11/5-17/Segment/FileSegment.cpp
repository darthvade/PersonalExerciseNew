/**
 *
 *  对某一文件进行切词处理
 *
 */

#include "./Jieba/MixSegment.hpp"
#include <unistd.h>
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<string>::iterator Iter;

void segment(CppJieba::MixSegment &seg, const string &filename, ofstream &output) {
	//evnet
	ifstream is(filename.c_str());	
	string temp;
	vector<string> result;
	while(getline(is, temp)) {
		seg.cut(temp, result);	
		for(Iter iter = result.begin(); iter != result.end(); ++iter) {
			output << *iter << " ";	
		}	
		output << endl;
		result.clear();
		temp.clear();
	}
}

int main() {
	const char * const JIEBA = "./dict/jieba.dict.utf8";
	const char * const HHM = "./dict/hmm_model.utf8";
	ofstream os("/home/kevin/SpiderData/dmoz/segfile.dat");
	CppJieba::MixSegment seg(JIEBA, HHM);
	segment(seg, "/home/kevin/SpiderData/dmoz/pagelib.dat", os);
	return 0;
}
