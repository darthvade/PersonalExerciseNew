/* 声明：本代码系本人原创
 * 说明：KMP算法的原始实现（未优化）
 */

#include <iostream>
#include <string>

using namespace std;


/*
 * 说明：求由模式串本身决定的特征向量
 *
 * @param pattern
 * [模式字符串]
 *
 * @return pointer to int[]
 * [特征向量]
 *
 */
int *next(const string &pattern) {
	if(pattern.size() == 0) {
		return NULL;
	}
	int *N = new int[pattern.size()];
	if(N == NULL) {
		return NULL;
	}
	N[0] = 0;
	for(std::size_t i = 1; i < pattern.size(); ++i) {
		int k = N[i - 1];	
		while(k > 0 && pattern[i] != pattern[k]) {
			k = N[k - 1];
		}
		if(pattern[i] == pattern[k]) {
			N[i] = k + 1;
		} else {
			N[i] = 0;
		}
	}
	return N;
}

/*
 * 说明：求模式串在目标串中出现的位置
 *
 * @param source
 * [目标字符串]
 *
 * @param pattern
 * [模式字符串]
 *
 * @return int
 * [模式串的第一个字符在目标串中出项的位置]
 * [若模式串长度大于目标串长度或]
 * [模式串不是目标串的一个字串]
 * [则函数返回-1]
 *
 */
int KMP_O1(const string &source, const string &pattern) {
	if(source.size() < pattern.size() || pattern.size() == 0) {
		return -1;
	}
	int *nextv = next(pattern);
	std::size_t j = 0;
	for(std::size_t i = 0; i < source.size() - pattern.size(); ++i) {
		while((source[i] != pattern[j]) && j > 0) {
			j = nextv[j - 1];
		}	
		if(source[i] == pattern[j]) {
			++j;	
		}
		if(j == pattern.size()) {
			delete [] nextv;
			return i - j + 1;
		}
	}
	delete [] nextv;
	return -1;
}

int main() {
	string src("aaaaaaaaabbbcdef");
	string pat("aaabbb");
	cout << KMP_O1(src, pat) << endl;
	return 0;
}
