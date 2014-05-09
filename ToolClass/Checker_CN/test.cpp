#include <iostream>
#include "Checker.h"
#include <string>

using namespace std;

int main() {
	string file("../../5-8/Segment/outputDirt");
	Checker checker(file);
	wstring target;
	while(true) {
		wcout << L"请输入待查汉字：";
		wcin >> target;
		wcout << endl;
		wcout << checker.findMostSimilarWord(target) << endl;
		wcout << checker.findTopKSimilarWords(target, 4) << endl;
		wcout << endl;
		wcout << L"查询完成！";
		wcout << endl;
	}
	return 0;
}
