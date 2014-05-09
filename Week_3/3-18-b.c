#include <stdio.h>

void max_headify(int *input, int i, int max_len); 

void build_max_heap(int *input, int max_len);

void heap_sort(int *input, int max_len);

void swap(int *a, int *b);

int main() {

	int input[] = {3, 5, 6, 1, 2, 6, 9, 4, 8};

	int len = sizeof(input) / sizeof(int);
	
	heap_sort(input, len);

	return 0;
}

void max_headify(int *input, int i, int max_len) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;
	if(l < max_len && input[l] > input[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if(r < max_len && input[r] > input[largest]) {
		largest = r;
	}
	if(i != largest) {
		//int temp = input[i];
		//input[i] = input[largest];
		//input[largest]= temp;
		swap(input + i, input + largest);
		max_headify(input, largest, max_len);
	}
}

void build_max_heap(int *input, int max_len) {
	int i;
	for(i = max_len / 2; i >= 0; i--) {
		max_headify(input, i, max_len);
	}
}

void heap_sort(int *input, int max_len) {
	int len = max_len;
	while(len > 0) {
		build_max_heap(input, len);
		swap(input, input + len - 1);
		len--;
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
