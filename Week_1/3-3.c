/**
*
*/
#include<stdio.h>

int main() {
	char *str1 = "hello";
	char str2[] = "hello";
	//printf("str1 :%x\n", &str1);
	//printf("str2 :%x\n", &str2);
	str2[2] = 'G';
	printf("str2 :%s\n", str2);
	str1[2] = 'A';
	return 0;	
}
