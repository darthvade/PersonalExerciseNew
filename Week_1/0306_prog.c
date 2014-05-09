#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define N 500

void Josephus();

int Mystrncmp(const char *a, const char *b, const int n);

int Mystrncpy(char *a, const char *b, const int n);

int main() {
	//Josephus();
	/*char str1[] = "hell";
	char str2[] = "abcde";
	printf("%d\n", Mystrncmp(str1, str2, 6));
	printf("%d->%s\n", Mystrncpy(str1, str2, 4), str1);*/

	system("pause");
	return 0;
}

void Josephus() {
	//约瑟夫环，静态链表法
	int m, n, i;
	int signal[N];
	int pre;
	int cur;
	int count = 1;
	scanf("%d,%d", &m, &n);
	for(i = 0; i < n - 1; i++) {
		signal[i] = i + 1;
	}
	signal[i] = 0;
	pre = n - 1;
	cur = 0;
	while(cur != signal[cur]) {
		if((count % m) == 0) {
			signal[pre] = signal[cur];
			cur = signal[cur];
			count = 1;
		} else {
			pre = cur;
			cur = signal[cur];
			count++;
		}
	}
	printf("this pos is : %d\n", cur + 1);
}

int Mystrncmp(const char *a, const char *b, const int n) {
	int i = 0;
	if(a == NULL || b == NULL) {
		return -1;
	}
	while(i < n) {
		if(a[i] > b[i]) {
			return 1;
		} else if(a[i] < b[i]) {
			return -1;
		} else if((a[i] == b[i]) != (i == n - 1)){
			i++;
			continue;
		} else if((a[i] == b[i]) && (i == n - 1)) {
			return 0;
		}
	}
}

int Mystrncpy(char *a, const char *b, const int n) {
	int i = 0;
	int len_a = strlen(a);
	if(a == NULL || b == NULL) {
		return -1;
	}
	if(n > len_a) {
		return -1;
	}
	while(i < n) {
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	return 1;
}