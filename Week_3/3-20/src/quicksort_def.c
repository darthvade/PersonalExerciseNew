#include "quicksort.h"

void quick_sort(int *input, const int start, const int end) {
	const int pivot_pos = partition(input, start, end);
	if(start < end - 1) {
		quick_sort(input, start, pivot_pos - 1);
		quick_sort(input, pivot_pos + 1, end);
	}
}//快速排序

int partition(int *input, const int start, const int end) {
	int i = start;
	int j;
	const int pivot = input[start];
	for(j = i + 1; j < end; j++) {
		if(input[j] <= pivot) {
			i++;
			swap(input + i, input + j);
		}
	}
	swap(input + start, input + i);
	return i;
}//快速排序的划分操作@

/*
void swap(int *a, int *b) {
	//位操作要注意输入的两个参数不能相同
	if(a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
*/

int topk(int *input, int k, int len) {

}//寻找有序数组input中第k大的数

int factorial(int n) {
	if(n == 1) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}//n的阶乘

int fibonacci(int n) {
	if(n == 0) {
		return 0;
	}
	else if(n == 1) {
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n -2);
	}
}//fibonacci数列

int fibonacci_v2(int *input, int n) {
	int i;
	input[0] = 0;
	input[1] = 1;
	for(i = 2; i < n; i++) {
		input[i] = input[i -1] + input[i - 2];
	}
}//fibonacci数列
