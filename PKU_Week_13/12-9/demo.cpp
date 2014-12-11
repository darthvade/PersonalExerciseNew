#include "./MySort.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;

void initFromFile(vector<int> &inputv, const string &inputfile) {
	ifstream f(inputfile);	
	int temp;
	while(f >> temp) {
		inputv.push_back(temp);	
	}
	f.close();
}

void writeToFile(vector<int> &outputv, const string &outputfile) {
	ofstream f(outputfile);
	for(auto i : outputv) {
		f << i << endl;	
	}
	f.close();
}

int main() {
	clock_t t;
	vector<int> vec;
	initFromFile(vec, "./initfile");
	//简单选择排序
	vector<int> vec1(vec);
	t = clock();
	MySort::SimpleSelectionSort(vec1, "INC");
	t = clock() - t;
	cout << "简单选择排序:" << (float)t / CLOCKS_PER_SEC << "s" << endl;
	writeToFile(vec, "outputfile-1");
	//冒泡排序
	vector<int> vec2(vec);
	t = clock();
	MySort::BubbleSort(vec2, "INC");
	t = clock() - t;
	cout << "冒泡排序:" << (float)t / CLOCKS_PER_SEC << "s" << endl;
	writeToFile(vec, "outputfile-2");
	//直接插入排序
	vector<int> vec3(vec);
	t = clock();
	MySort::StraightInsertionSort(vec3, "INC");
	t = clock() - t;
	cout << "直接插入排序:" << (float)t / CLOCKS_PER_SEC << "s" << endl;
	writeToFile(vec, "outputfile-3");

	return 0;
}
