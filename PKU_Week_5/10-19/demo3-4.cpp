#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.length() != s2.length()) {
		s1.length() > s2.length() ? cout << s1 << endl : cout << s2 << endl;
	} else {
		cout << "equal!" << endl;
	}
}
