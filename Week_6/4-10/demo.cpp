#include <bitset>
#include <iostream>
#include <string>

using namespace std;

const string& shorter(const string &a, const string &b) {
	return (a > b) ? b : a;
}

bool cmp(int a, int b) {
	return a > b;
}

void bubble_sort(int *start, int n, bool (*cmp)(int, int)) {
	int flag = 0;
	for(int i = 0; i < n; i++)	{
		flag = 0;
		for(int j = n - 1; j > i ; j--) {
			if(cmp(start[j - 1], start[j])) {
				int temp = start[j];
				start[j] = start[j - 1];
				start[j - 1] = temp;	
				flag = 1;
			}
		}
		if(flag == 0) {
			return;
		}
	}
}

int main() {

	string a = "aaaabbbbb";
	string b = "cccc";

	const string& (*hehe)(const string&, const string&);

	hehe = shorter;

	cout << shorter(a, b) << endl;

	cout << hehe(a, b) << endl;

	int sort[] = {6, 9, 8, 4, 2, 6, 9};

	bubble_sort(sort, sizeof(sort) / sizeof(int), cmp);

	for(int i = 0; i !=	(sizeof(sort) / sizeof(int)); i++) {
		cout << sort[i] << endl;	
	}

	return 0;
}
