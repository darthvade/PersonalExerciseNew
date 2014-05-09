#include <iostream>

using namespace std;

void fun(int (&input)[5]) {
	cout << *input << endl;	
}

void fun2(...) {
	cout << "Hello world" << endl;	
}

int main() {

	int arr[5] = {1, 2, 3, 4, 5};
	int arr2[4] = {1, 2, 3, 4};
	fun(arr);
	fun2(arr2, arr);

}
