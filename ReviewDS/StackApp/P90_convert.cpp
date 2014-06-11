/**
 *
 *	将十进制转换到任意进制
 *
 */
#include <stack>
#include <iostream>
#include <cstdlib>

using namespace std;

//将input转化成n进制
stack<char> convert(int input, int n) {
	char base[] = {'0', '1', '2', '3', '4', '5',
					'6', '7', '8', '9', 'A', 'B',
					'C', 'D', 'E', 'F'};
	stack<char> result;
	while(input > 0) {
		result.push(base[input % n]);
		input /= n;
	}
	return result;
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		return 1;
	}
	stack<char> result = convert(atoi(argv[1]), atoi(argv[2]));	
	while(!result.empty()) {
		cout << result.top();
		result.pop();
	}
	cout << endl;
	return 0;
}
