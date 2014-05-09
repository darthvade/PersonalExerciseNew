#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void Bubble_sort(int *a, const int start, const int end);

void Sample_selection_sort(int *a, const int start, const int end);

void Straight_insertion_sort(int *a, const int start, const int end);

void Shell_sort(int *a, const int start, const int end);

void shell_insert(int *a, const int start, const int end, const int gap);

void swap(int *a, int *b);

void printInput(const int *a);

int main() {
	
	//√∞≈›≈≈–Ú°¢ºÚµ•—°‘Ò≈≈–Ú°¢÷±Ω”≤Â»Î≈≈–Ú°¢œ£∂˚≈≈–Ú
	int input[N];
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++) {
		input[i] = rand() / 100;
	}
	printInput(input);
	//Bubble_sort(input, 0, N);
	//Sample_selection_sort(input, 0, N);
	//Straight_insertion_sort(input, 0, N);
	//Shell_sort(input, 0, N);
	printInput(input);

	system("pause");
	return 0;
}

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
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
	/*int temp;
	temp = *a;
	*a = *b;
	*b = temp;*/
}

void printInput(const int *a) {
	int i;
	for(i = 1; i <= N; i++) {
		printf("%3d -- > %3d\n", i, a[i - 1]);
	}
	putchar('\n');
}