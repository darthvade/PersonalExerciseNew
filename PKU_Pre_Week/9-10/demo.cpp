/*
 *  Problem: given n, find the number of different ways 
 *	to write � as the sum of 1, 3, 4
 */

#include <iostream>

using namespace std;

int arr[10000];

int main() {
	arr[0] = 1;	
	arr[1] = 1;	
	arr[2] = 1;	
	arr[3] = 2;	
	int n;
	cin >> n;
	for(int i = 4; i <= n; ++i) {
		arr[i] = arr[i - 1] + arr[i - 3] + arr[i - 4];	
	}
	cout << arr[n] << endl;
	return 0;
}
