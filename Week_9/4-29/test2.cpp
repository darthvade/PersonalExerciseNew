#include <iostream>

void swap(int **a, int **b) {
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int *&a, int *&b) {
	int *temp;
	temp = a;
	a = b;
	b = temp;
}

int strlen(const char* str) {
	const char *p = str;
	p++;
}

int main() {
	return 0;
}
