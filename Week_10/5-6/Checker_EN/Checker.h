/**
 *	Checker类
 *
 * （英文字符版）
 *
 *	作用：用于寻找某单词的最相近单词
 *  注：使用编辑距离算法
 *
 */

#ifndef __CHECKER_H__
#define __CHECKER_H__

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>

struct WordInfo {
	int index; 	//单词在词典中的下标
	int editdis;  //单词与查询词的编辑距离
	int frequence; //单词词频
};

/*建堆规则*/
struct Compare {
	bool operator() (const WordInfo &a, const WordInfo &b) {
		bool status = true;
		if(a.editdis > b.editdis) {
			status = true;
		} else if (a.editdis == b.editdis) {
			if(a.frequence < b.frequence) {
				status = true;
			}
		} else {
			status = false;
		}
		return status;
	}
};

class Checker {
public:
	Checker(const std::string &); //使用词典文件初始化
	~Checker();
	std::string findMostSimilarWord(const std::string &); //寻找最相近单词（编辑距离算法）
	std::string findTopKSimilarWords(const std::string &, int); //寻找最相近的前K个单词
private:
	typedef std::vector<std::string>::iterator Iter;
	typedef std::map<std::string, int>::iterator MapIter;

	void readFileToVec(const std::string &); //将文件中的单词读入到数组
	int editDistance(const std::string &, const std::string &); //计算编辑距离
	std::string& cleanPunc(std::string &); //字符串去标点

	std::vector<std::string> _words_vec; //单词字典
	std::map<std::string, int> _words_counter; //单词词频
};

inline int min(const int &a, const int &b, const int &c) {
	int t = a < b ? a : b;
	return t < c ? t : c;
}

#endif
