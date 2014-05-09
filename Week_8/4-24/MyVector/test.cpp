#include <iostream>
#include "MyVector.h"

using namespace std;

int main() {
	/*
	vector<int> vec(30);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	*/
	MyVector vec1;
	MyVector vec2(30);
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	MyVector vec3(a, a + 5);
	cout << vec1.size() << " " << vec1.capacity() << endl; 
	cout << vec2.size() << " " << vec2.capacity() << endl; 
	cout << vec3.size() << " " << vec3.capacity() << endl; 
	cout << vec1 << endl;
	cout << vec2 << endl;
	cout << vec3 << endl;
	vec3.insert(4, 99);
	cout << vec3 << endl;
	cout << vec3.size() << endl;
	cout << vec3.capacity() << endl << endl;
	
	MyVector vec4;
	for(int i = 0; i != 20; ++i) {
		vec4.push_back(i);
		cout << vec4.size() << endl;
		cout << vec4.capacity() << endl << endl;
	}
	cout << vec4 << endl;
	cout << vec4.size() << endl;
	cout << vec4.capacity() << endl << endl;

/*	
	MyVector vec5;
	vec5.push_back(99);
	vec5.push_back(99);
	vec5.push_back(99);
	cout << vec5 << endl;
*/
	return 0;
}
