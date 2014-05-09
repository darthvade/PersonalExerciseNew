#include<stdio.h>
int main() {
	printf("core dump\n");
	*(char *)0 = 0;
	return 0;
}
