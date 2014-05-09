/**
* C++基础语法练习
*/
#include<iostream>
using namespace std;
void fun(int a = 2, int b = 2);
void fun2(int a = 2, int b = 2, int c = 2);

int main() {
	fun();
	fun2();
	return 0;
}

void fun(int a, int b){
	cout << a << " " << b << endl;
}

void fun2(int a, int b, int c){
	cout << a << " " << b << " " << c << endl;
}
