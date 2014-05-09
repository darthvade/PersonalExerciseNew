/**
 *	LCS 最长公共子序列
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline int max(int &a, int &b) {
	return a > b ? a : b;
}

/*递归算法*/
int LongestCommonSubsequence(string &x, string &y, int i, int j) {
	if(i == 0 || j == 0) {
		return 0;
	}
	if(x[i - 1] == y[j - 1]) {
		return LongestCommonSubsequence(x, y, i - 1, j - 1) + 1;
	} else {
		return max(LongestCommonSubsequence(x, y, i - 1, j), LongestCommonSubsequence(x, y, i, j - 1));
	}
}

int main() {
	string s1("abcbdab");
	string s2("bdcaba");
	int l = LongestCommonSubsequence(s1, s2, s1.size(), s2.size());
	cout << l << endl;
	return 0;
}


