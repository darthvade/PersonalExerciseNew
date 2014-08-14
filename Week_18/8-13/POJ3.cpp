//POJ2136

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

char arr[100][100];

int counter[100];

int main() {
	string temp;
	while(cin >> temp) {
		for(size_t i = 0; i < temp.size(); ++i) {
			if(ispunct(temp[i]) || temp[i] == ' ') {
				continue;
			}
			counter[temp[i] - 'A']++;	
		}
	}
	//DEBUG
	//for(size_t i = 0; i < 26; ++i) {
	//	cout << counter[i] << endl;
	//}
	int largest_counter = 0;
	for(int i = 0; i < 26; ++i) {
		if(largest_counter < counter[i]) {
			largest_counter = counter[i];
		}
		arr[i][0] = 'A' + i;
		for(int j = 1; j <= counter[i]; ++j) {
			arr[i][j] = '*';	
		}
	}	
	//debug
	//for(int i = 0; i < 26; ++i) {
	//	for(int j = 0; j <= largest_counter; ++j) {
	//		cout << arr[i][j];
	//		if(j == largest_counter) {
	//			cout << endl;
	//		}
	//	}
	//}
	//print
	for(int i = largest_counter; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) {
			if(arr[j][i] == 0) {
				cout << ' ' << ' ';
			} else {
				cout << arr[j][i] << ' ';
			}
			if(j == 25) {
				cout << endl;
			}
		}	
	}
	return 0;
}
