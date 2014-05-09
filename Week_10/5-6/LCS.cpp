#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline int max(int &a, int &b) {
	return a > b ? a : b;
}

int LCS(string &a, string &b) {
	int x = a.size();
	int y = b.size();
	int memo[x + 1][y + 1];
	memset(memo, 0, sizeof(memo));	
	for(int i = 1; i <= x; ++i) {
		for(int j = 1; j <= y; ++j) {
			if(a[i - 1] == b[j - 1]) {
				memo[i][j] = memo[i - 1][j - 1] + 1;
			} else {
				memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);	
			}
		}	
	}
	/*DEBUG*/ 
	for(int i = 0; i <= x; ++i) {
		for(int j = 0; j <= y; ++j) {
			cout << "  " <<memo[i][j];		
		}
		cout << endl;
	} 

	return memo[x][y];
}

int main() {
	string s1("abcdef");
	string s2("ebcf");	
	cout << LCS(s1, s2) << endl;
	return 0;
}
