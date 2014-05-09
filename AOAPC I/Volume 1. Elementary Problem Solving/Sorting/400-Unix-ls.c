/**
*  400 - Unix ls
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[100][65];

int n;

int maxl;

void input();

void solve();

void output();

int cmp(const void *a, const void *b);

int main() {
	#ifdef KEVIN
		freopen("input", "r", stdin);	
		freopen("output", "w", stdout);
	#endif
	while(scanf("%d", &n) == 1) {
		input();
		solve();
		output();
	}
	return 0;
}

void input() {
	int i = 0;
	int j = n;
	maxl = 0;
	while(j--) {
		scanf("%s", array[i]);
		if(strlen(array[i]) > maxl) {
			maxl = strlen(array[i]);
		}
		i++;
	}
}

int cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

void solve() {
	int i = n;
	qsort(array, i, sizeof(array[0]), cmp);	
}

void output() {
	int line = 60;
	while(line--) {
		printf("-");
		if(0 == line) {
			printf("\n");
		}
	}
/*	
	int i = 0;
	while(i < n) {
		int more = maxl - strlen(array[i]);
		printf("%s--------> %d\n", array[i++], maxl);
	}
*/
	int maxcol = 62 / (maxl + 2);
	int inc = 0;
	if(n % maxcol == 0) {
		inc = n / maxcol;
	} else {
		inc = n / maxcol + 1;
	}
	int i = 0;
	while(i < inc) {
		int j = i;
		while(j < n) {
			int more = maxl - strlen(array[j]) + 2;
			printf("%s", array[j]);
			while(more) {
				printf(" ");
				more--;
			}
			j = j + inc;
		}
		printf("\n");
		i++;
	}
}












