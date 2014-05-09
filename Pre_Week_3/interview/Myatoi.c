/**
*	Myatoi(转换范围受限！)
*/
#include<stdio.h>
#include<string.h>
int Myatoi(const char *a);
int main() {
	char a[] = "1234";
	printf("%d\n", Myatoi(a));
	return 0;
}

int Myatoi(const char *a) {
	int len = strlen(a);
	int i, result = 0;
	for(i = 0; i < len; i++) {
		result = 10 * result + a[i] - '0';
	}
	return result;
}

