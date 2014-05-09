#include <iostream>
#include "Checker.h"
#include <string>

using namespace std;

int main() {
	string file("/home/kevin/MyProjects/SpellChecker/data/big.txt");
	Checker checker(file);
	string target;
	while(true) {
		cout << "Please input target string: ";
		cin >> target;
		cout << endl;
		cout << checker.findMostSimilarWord(target) << endl;
		cout << checker.findTopKSimilarWords(target, 4) << endl;
		cout << endl;
		cout << "finished!";
		cout << endl;
	}
	return 0;
}
