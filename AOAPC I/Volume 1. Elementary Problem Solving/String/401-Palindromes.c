/**
* 401 - Palindromes
*/
#include<stdio.h>
#include<string.h>
#define MAXLEN 20

char str[MAXLEN];

int isPalindromes(const char* str);/*判断是否是回文串*/

int isMirror(const char* str);/*判断是否是镜面对称串*/

char charReverse(const char c);/*返回所给字符的镜面字符*/

void test_and_print(const char* str);/*测试并打印字符串*/

int main() {
	#ifdef KEVIN /*注：编译选项加DKEVIN*/
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
	#endif
	/* 测试用
	char *str1 = "ATYOTA";
	char *str2 = "2A3MEAS";	
	printf("%d\n%d\n", isPalindromes(str1), isMirror(str2));
	*/
	while(scanf("%s", str) != EOF) {
		test_and_print(str);
		printf("\n\n");
	}
	return 0;
}

void test_and_print(const char* str) {
	int score = 0;
	if(isPalindromes(str)) {
		score = score + 1;
	} 
	if(isMirror(str)) {
		score = score + 2;
	} 
	switch(score) {
		case 0:
			printf("%s -- is not a palindrome.", str); break;
		case 1:
			printf("%s -- is a regular palindrome.", str); break;
		case 2:
			printf("%s -- is a mirrored string.", str); break;
		case 3:
			printf("%s -- is a mirrored palindrome.", str); break;
		default : break;
	}
	return;
}

int isPalindromes(const char* str) {
	int len = strlen(str);
	int i = 0;
	while(str[i] == str[len - 1 - i]) {
		i++;
		if(i >= (len / 2)) {
			return 1;
		}
	}
	return 0;
}

int isMirror(const char* str) {
	int len = strlen(str);
	int i = 0;
	while(str[i] == charReverse(str[len - 1 - i])) {
		i++;
		if(i >= (len / 2)) {
			return 1;
		}
	}
	return 0;
}

char charReverse(const char c) {
	switch(c) {
		case 'A': return 'A';
		case 'E': return '3';
		case 'H': return 'H';
		case 'I': return 'I';
		case 'J': return 'L';
		case 'L': return 'J';
		case 'M': return 'M';
		case 'O': return 'O';
		case 'S': return '2';
		case 'T': return 'T';
		case 'U': return 'U';
		case 'V': return 'V';
		case 'W': return 'W';
		case 'X': return 'X';
		case 'Y': return 'Y';
		case 'Z': return '5';
		case '1': return '1';
		case '2': return 'S';
		case '3': return 'E';
		case '5': return 'Z';
		case '8': return '8';
		default : return 0;
	}
}
