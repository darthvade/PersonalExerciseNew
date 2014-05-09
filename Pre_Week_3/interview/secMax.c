/**
* 数组的第二大元素
*/
#include<stdio.h>

int sec_max(const int *a, int n);

int main() {
	int a[] = {5, 9, 5, 9, 4, 3, 8, 7};
	int pos = sec_max(a, 8);
	printf("%d\n", a[pos]);
	return 0;
}

int sec_max(const int *a, int n) {
	int max;
	int pre;
	int i;
	if(a[0] > a[1]) {
		max = 0;
		pre = 1;
	} else {
		max = 1;
		pre = 0;
		for(i = 0; i < n; i++) {
			if(a[i] >= a[max]) {
				max = i;
			} else if(a[i] > a[pre]) {
				pre = i;
			}
		}
	}
	return pre;
}

