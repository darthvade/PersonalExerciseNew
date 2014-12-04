#include <string>
#include <iostream>

using namespace std;

int main() {
	string a, b;
	do {
		if(!a.empty() || !b.empty()) {
			cout << (a.size() > b.size() ? a : b) << endl;
		}
		cout << "请输入两个字符串" << endl;
	} while (cin >> a >> b);
	return 0;
}
