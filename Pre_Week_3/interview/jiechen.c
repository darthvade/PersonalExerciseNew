/**
*
*/
#include<stdio.h>
int jiechen(int n);
int main() {
	printf("%d\n", jiechen(2));
	return 0;
}

int jiechen(int n) {
	if(n == 1) {
		return 1;
	}
	return n*jiechen(n - 1);
}
