#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
	bitset<32> bt1("101001");
	bitset<32> bt2(0xF);
	//cout << bt1.flip() << endl;
	cout << bt1 << endl;
	cout << bt2 << endl;
	return 0;
}
