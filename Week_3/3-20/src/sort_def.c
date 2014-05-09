#include "sort.h"

void Bubble_sort(int *a, const int start, const int end) {
	int i;
	int j;
	int exchange;
	for(i = start; i < end; i++) {
		exchange = 0;
		for(j = end - 1; j > i; j--) {
			if(a[j] < a[j - 1]) {
				swap(a + j, a + j - 1);
				exchange = 1;
			}
		}
		if(0 == exchange) {
			return;
		}
	}
}

void Sample_selection_sort(int *a, const int start, const int end) {
	int i;
	int j;
	int k;
	for(i = start; i < end; i++) {
		k = i;
		for(j = i + 1; j < end; j++) {
			if(a[j] < a[k]) {
				k = j;
			}
		}
		if(k != i) {
			swap(a + i, a + k);
		}
	}
}

void Straight_insertion_sort(int *a, const int start, const int end) {
	int i;
	int j;
	int temp;
	for(i = start + 1; i < end; i++) {
		temp = a[i];
		for(j = i - 1; j >= start && a[j] > temp; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void Shell_sort(int *a, const int start, const int end) {
	int gap = end - start;
	while(gap > 1) {
		gap = gap / 3 + 1;
		shell_insert(a, start, end, gap);
	}
}

void shell_insert(int *a, const int start, const int end, const int gap) {
	int i;
	int j;
	int temp;
	for(i = start + gap; i < end; i++) {
		temp = a[i];
		for(j = i - gap; j >= start && a[j] > temp; j = j - gap) {
			a[j + gap] = a[j];
		}
		a[j + gap] = temp;
	}
}

void swap(int *a, int *b) {
	if(*a != *b) {
		*a = (*a)^(*b);
		*b = (*a)^(*b);
		*a = (*a)^(*b);
	}
	/*int temp;
	temp = *a;
	*a = *b;
	*b = temp;*/
}

void printInput(const int *a, int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%3d -- > %3d\n", i, a[i]);
	}
	putchar('\n');
}

void heap_sort(int *a, const int n) {
	heap_init(a, n);
	int i;
	for(i = n - 1; i >= 0; i--) {
		swap(a + i, a);
		heap_adjust(a, 0, i);
	}
}  //堆排序

void heap_adjust(int *a, const int i, const int n) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;
	if(l < n && a[i] < a[l]) {
		largest = l;
	} else {
		largest = i;
	}
	if(r < n && a[largest] < a[r]) {
		largest = r;
	}
	if(i != largest) {
		swap(a + i, a + largest);
		heap_adjust(a, largest, n);
	}
} //调整堆

void heap_init(int *a, const int n) {
	int i;
	for(i = n / 2; i >= 0; i--) {
		heap_adjust(a, i, n);
	}
} //初始堆


