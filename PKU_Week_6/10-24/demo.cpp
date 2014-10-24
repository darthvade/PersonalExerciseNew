#include <iostream>
#include <vector>

using namespace std;

void print1(int a[3][4]) {
			for(auto &row : a) {
							for(auto &col : row) {
												cout << col;
														}
								}
}

void print2(int a[][4], int n, int m) {
			for(int i = 0; i < n; ++i) {
							for(int ib = 0; ib < m; ++ib) {
									   			cout << a[i][ib];
														}
								}
}

void print3(int a[][4]) {
			for(int (*p)[4] = &a[0]; p != NULL; ++p) {
							for(int *pp = p[0]; pp != NULL; ++pp) {
												cout << *pp;
														}
								}
}

int main() {
	std::vector<int> heh;
	heh.push_back(100);
	for(auto i : heh) {
		cout << i << endl;
	}
	return 0;
}
