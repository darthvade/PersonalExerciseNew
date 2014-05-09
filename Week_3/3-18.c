#include <stdio.h>

void reverse_print(const int *array, int i, int n); // print the linkarray from rear to front

int main() {

	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	int len = sizeof(array) / sizeof(int);

	reverse_print(array, 0, len);

	putchar('\n');
}

void reverse_print(const int *array, int i, int n) {
	if(i < n) {
		reverse_print(array, i + 1, n);
		printf("%d ", array[i]);
	}
}
