/**
*
*/
#include<stdio.h>
#define BOOL_1 int
typedef int BOOL_2;
int main() {
	BOOL_1 a;
	BOOL_2 b;
	printf("%d\n", sizeof(BOOL_1));
	printf("%d\n", sizeof(BOOL_2));
	return 0;
}
