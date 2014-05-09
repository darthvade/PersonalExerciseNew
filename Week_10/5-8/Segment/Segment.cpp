/**
 *
 *  对某一目录下的所有文件进行切词处理
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

void segment(CppJieba::MixSegment &seg, const string &dirt, ofstream &output) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(dirt.c_str())) == NULL) {
		cout << "open dirt failed!" << endl;	
		return;
	}
	chdir(dirt.c_str());	
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf);	
		if(S_ISDIR(statbuf.st_mode)) {
			/*忽略.和..目录*/
			if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)	{
				continue;	
			}
			//递归遍历
			segment(seg, string(entry->d_name), output);
		}
		//evnet
		ifstream is(entry->d_name);	
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
	chdir("..");
	closedir(dp);
}

int main() {
	const char * const JIEBA = "./dict/jieba.dict.utf8";
	const char * const HHM = "./dict/hmm_model.utf8";
	ofstream os("/home/kevin/SegmentDict/segresult");
	CppJieba::MixSegment seg(JIEBA, HHM);
	segment(seg, "/home/kevin/UnSegmentDict/utf/hjeh", os);
	return 0;
}
