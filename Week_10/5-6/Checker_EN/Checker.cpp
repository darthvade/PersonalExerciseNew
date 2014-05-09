#include "Checker.h"

Checker::Checker(const std::string &filename) : 
_words_vec(),
_words_counter() {
	readFileToVec(filename);
}

Checker::~Checker() {

}

std::string Checker::findMostSimilarWord(const std::string &target) {
	int minIndex = 0, index = 0;
	int minDistance = 50000;
	for(Iter iter = _words_vec.begin(); iter != _words_vec.end(); ++iter) {
		int tempDistance = editDistance(*iter, target);	
		if(tempDistance < minDistance) {
			minIndex = index;		
			minDistance = tempDistance;
		} else if (tempDistance == minDistance) {
			if(_words_counter[*iter] > _words_counter[_words_vec[minIndex]]) {
				minIndex = index;		
				minDistance = tempDistance;
			}	
		}
		index++;
	}
	return _words_vec[minIndex];
} 

std::string Checker::findTopKSimilarWords(const std::string &target, int k) {
	std::priority_queue<WordInfo, std::vector<WordInfo> ,Compare> _pri_queue_words; //编辑距离优先级队列
	std::string result;
	int index = 0;
	for(Iter iter = _words_vec.begin(); iter != _words_vec.end(); ++iter) {
		WordInfo info;
		info.index = index;
		info.frequence = _words_counter[*iter];
		info.editdis = editDistance(*iter, target);
		_pri_queue_words.push(info);
		index++;
	}
	while(k--) {
		result = result + _words_vec[_pri_queue_words.top().index];
		result += " ";
		_pri_queue_words.pop();
	}	
	return result;
}

void Checker::readFileToVec(const std::string &filename) {
	std::ifstream is;
	is.close();
	is.clear();
	is.open(filename.c_str());
	if(!is) {
		std::cout << "File open failed" << std::endl;
	}
	std::string temp;
	while(getline(is, temp)) {
		std::string word;
		std::stringstream ss(cleanPunc(temp));			
		while(ss >> word) {
			//_words_vec.push_back(word);	
			++_words_counter[word];
			ss.clear();
		}
		is.clear();
	}
	//_words_vec.clear();
	for(MapIter iter = _words_counter.begin(); iter != _words_counter.end(); ++iter) {
		_words_vec.push_back((*iter).first);	
	}
}

int Checker::editDistance(const std::string &a, const std::string &b) {
	int x = a.size();
	int y = b.size();
	int memo[x + 1][y + 1];
	memset(memo, 0, sizeof(memo));
	for(int i = 0; i <= x; ++i) {
		memo[i][0] = i;
	}
	for(int j = 0; j <= y; ++j) {
		memo[0][j] = j;
	}
	for(int i = 1; i <= x; ++i) {
		for(int j = 1; j <= y; ++j) {
			int cost = (a[i - 1] == b[j - 1] ? 0 : 1);
			int del = memo[i - 1][j] + 1;
			int ins = memo[i][j - 1] + 1;
			int sub = memo[i - 1][j - 1] + cost; 
			memo[i][j] = min(del, ins, sub);
		}
	}
	return memo[x][y];
}

std::string& Checker::cleanPunc(std::string &str) {
	for(std::string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		if(ispunct(*iter)) {
			*iter = ' ';
		}	
	}	
	return str;
}
