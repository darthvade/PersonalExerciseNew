#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<int> vec1(10, 88);
	for(std::size_t ix = 0; ix != vec1.size(); ++ix) {
		cout << vec1[ix] << endl;
	}

	cout << "__________" << endl;
	vector<int> vec2(vec1);
	for(std::size_t ix = 0; ix != vec2.size(); ++ix) {
		cout << vec2[ix] << endl;
	}
	
	cout << "__________" << endl;
	vector<int> vec3(vec1.begin(), vec1.begin() + vec1.size() / 2);
	for(std::size_t ix = 0; ix != vec3.size(); ++ix) {
		cout << vec3[ix] << endl;
	}

	cout << "__________" << endl;
	vector<int> vec4(5, 99);
	vec1 = vec4;
	for(std::size_t ix = 0; ix != vec1.size(); ++ix) {
		cout << vec1[ix] << endl;
	}


}
