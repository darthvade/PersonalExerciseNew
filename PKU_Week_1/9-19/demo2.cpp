#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int main() {
	tuple<int, string, vector<int> > t1;
	get<2>(t1).push_back(100);
	get<2>(t1).push_back(99);
	get<2>(t1).push_back(12);
	get<0>(t1) = 9999;
	get<1>(t1) = "hehe";
	cout << get<1>(t1) << endl;

	tuple<int, string, vector<int> > t2(99, "hello", {2, 8, 99, 100});
	cout << get<2>(t2)[3] << endl;
	cout << tuple_size<decltype(t2)>::value << endl;

	cout << (t1 > t2) << endl;
	return 0;
}
