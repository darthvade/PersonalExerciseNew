#include <vector>
#include <iostream>

using namespace std;

int main() {
	std::vector<int> lst;
	auto cap = lst.capacity();
	for(long long i = 1; i <= 10000000000; ++i) {
		lst.push_back(i);
		if(cap != lst.capacity()) {
			cap = lst.capacity();
			cout << cap << endl; 
		}
	}
	cout << "-------------------" << endl;
	cout << lst.size() << endl;
	cout << lst.capacity() << endl;
	cout << lst.max_size() << endl;
	cout << "-------------------" << endl;
	std::vector<int> hehe;
	lst.swap(hehe);
	//lst.shrink_to_fit();
	cout << lst.size() << endl;
	cout << lst.capacity() << endl;
	cout << lst.max_size() << endl;
	return 0;
}
