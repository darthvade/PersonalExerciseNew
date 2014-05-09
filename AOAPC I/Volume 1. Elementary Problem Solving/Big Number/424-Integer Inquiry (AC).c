/**
* 424 - Integer Inquiry 
*/
#include<string.h>
#include<stdio.h>
#define MAXLEN 110

char str[MAXLEN];
int num[MAXLEN];

void solve() {
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++) {
		num[i] += str[len - 1 - i] - '0';
		if(num[i] > 9) {
			num[i] %= 10; num[i + 1] += 1;
		}
	}
}

void output() {
	int i, j;
	for(i = MAXLEN; i >= 0; i--) {
		if(num[i] != 0) break;
	}
	for(j = i; j >= 0; j--) {
		printf("%d", num[j]);
	}
	printf("\n");
}

void input() {
	while(scanf("%s", str) == 1) {
		if(str[0] == '0') break;
		solve();
	}
}

int main() {
	memset(num, 0, sizeof(num));
	input();
	output();
	return 0;
}




