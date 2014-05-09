#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline int min(const int &a, const int &b, const int &c) {
	int t = a < b ? a : b;
	return t < c ? t : c;
}

int ED(wstring &a, wstring &b) {
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
	/*DEBUG*/
	for(int i = 0; i <= x; ++i) {
		for(int j = 0; j <= y; ++j) {
			cout << "  " << memo[i][j];		
		}
		cout << endl;
	} 

	return memo[x][y];
}

int main() {

	wstring s1(L"北京市");
	wstring s2(L"北京欢迎您");
	cout << ED(s1, s2) << endl;
	return 0;

}
