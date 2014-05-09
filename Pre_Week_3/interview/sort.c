/**
*
*/
#include<stdio.h>

typedef int elem_t;

/*二分查找*/
int binary_search(const elem_t *a, const int n, const elem_t x);

/*直接插入排序*/
void straight_insertion_sort(elem_t *a, const int start, const int end);

/*折半插入排序*/
void binary_insertion_sort(elem_t *a, const int start, const int end);

/*希尔插入排序*/
void shell_insertion_sort(elem_t *a, const int start, const int end);
static void shell_sort(elem_t *a, const int start, const int end, int gap);

/*冒泡排序*/
void bubble_sort(elem_t *a, const int start, const int end);

/*快速排序*/
void quick_sort(elem_t *a, const int start, const int end);
int partition(elem_t *a, const int start, const int end);

/*简单选择排序*/
void sample_selection_sort(elem_t *a, const int start, const int end);

/*堆排序*/
//void heap_sort(elem_t *a, const int start, const int end);/*未实现*/

/*归并排序*/
void merge_sort(elem_t *a, elem_t *tmp, const int start, const int end);
static void merge(elem_t *a, elem_t *tmp, const int start, const int mid, const int end);

/*基数排序*/
//void radix_sort(static_list_node_t *a, const int n, const int d);/*未实现*/

/*打印数组*/
void print_array(const elem_t *a, const int n);

/*交换两个元素的值*/
static inline void swap(elem_t *a, elem_t *b);

int main() {
	elem_t arr_a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//elem_t arr_b[10] = {9, 1, 2, 5, 4, 3, 6, 8, 7, 0};
	elem_t arr_b[10] = {9, 1};
	print_array(arr_b, 10);
	//printf("%d\n", binary_search(arr_a, 10, 3));/*二分查找*/
	//straight_insertion_sort(arr_b, 0, 10);/*直接插入排序*/
	//binary_insertion_sort(arr_b, 0, 10);/*折半插入排序*/
	//shell_insertion_sort(arr_b, 0, 10);/*希尔插入排序*/
	//bubble_sort(arr_b, 0, 10);/*冒泡排序*/
	quick_sort(arr_b, 0, 10);/*快速排序*/
	//sample_selection_sort(arr_b, 0, 10);/*简单选择排序*/
	//merge_sort(arr_b, arr_a, 0, 10);/*归并排序*/
	print_array(arr_b, 10);
	return 0;
}

void print_array(const elem_t *a, const int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d --> %d\n", i, a[i]);
	}
	printf("\n");
}

int binary_search(const elem_t *a, const int n, const elem_t x) {
	int left = 0, right = n - 1, mid = 0;
	while(left <= right) {
		mid = left + (right - left) / 2;/*注意*/
		if(a[mid] > x) {
			right = mid - 1;
		}
		else if(a[mid] < x){
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

void straight_insertion_sort(elem_t *a, const int start, const int end) {
	int i, j;
	elem_t tmp;
	for(i = start + 1; i < end; i++) {
		tmp = a[i];
		for(j = i - 1; j >= start && a[j] > tmp; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}

void binary_insertion_sort(elem_t *a, const int start, const int end) {
	int i, j, left, right, mid;
	elem_t tmp;
	for(i = start + 1; i < end; i++) {
		tmp = a[i];
		left = start, right = i - 1;
		while(left <= right) {
			mid = left + (right - left) / 2;
			if(a[mid] > tmp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for(j = i - 1; j >= left; j--) {
			a[j + 1] = a[j];
		}
		a[left] = tmp;
	}
}

static void shell_sort(elem_t *a, const int start, const int end, int gap) {
	int i, j;
	elem_t tmp;
	for(i = start + gap; i < end; i++) {
		tmp = a[i];
		for(j = i - gap; j >= start && a[j] >= tmp; j = j - gap) {
			a[j + gap] = a[j];
		}
		a[j + gap] = tmp;
	}
}
void shell_insertion_sort(elem_t *a, const int start, const int end) {
	int gap = end - start;
	while(gap > 1) {
		gap = gap / 3 + 1;
		shell_sort(a, start, end, gap);
	}
}

void bubble_sort(elem_t *a, const int start, const int end) {
	int i, j, exchange;
	for(i = start; i < end; i++) {
		exchange = 0;
		for(j = end - 1; j > i; j--) {
			if(a[j] < a[j - 1]) {
				swap(a+j, a+j-1);
				exchange = 1;
			}
		}
		if(exchange == 0) {
			return;
		}
	}
}

static inline void swap(elem_t *a, elem_t *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(elem_t *a, const int start, const int end) {
	if(start < end - 1) {
		const int pivot_pos = partition(a, start, end);
		quick_sort(a, start, pivot_pos);
		quick_sort(a, pivot_pos + 1, end);
	}
}

int partition(elem_t *a, const int start, const int end) {
	int i = start;
	int j = end - 1;
	const elem_t pivot = a[i];
	while(i < j) {
		while(i < j && a[j] >= pivot) j--;
		a[i] = a[j];
		while(i < j && a[i] <= pivot) i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	return i;
}

void sample_selection_sort(elem_t *a, const int start, const int end) {
	int i, j;
	int tmp;
	for(i = start; i < end; i++) {
		tmp = i;
		for(j = i; j < end; j++) {
			if(a[j] < a[tmp]) {
				tmp = j;
			}
		}
		swap(a + i, a + tmp);
	}
}


static void merge(elem_t *a, elem_t *tmp, const int start, const int mid, const int end) {
	int i, j, k;
	for(i = start; i < end; i++) {
		tmp[i] = a[i];
	}
	for(i = start, j = mid, k = start; i < mid && j < end && k < end; k++) {
		if(tmp[i] > tmp[j]) {
			a[k] = tmp[j++];
		} else {
			a[k] = tmp[i++];
		}
	}
	while(i < mid) {
		a[k++] = tmp[i++];
	}
	while(j < end) {
		a[k++] = tmp[j++];
	}
}

void merge_sort(elem_t *a, elem_t *tmp, const int start, const int end) {
	if((end - start) > 1) {
		const int mid = start + (end - start) / 2;
		merge_sort(a, tmp, start, mid);
		merge_sort(a, tmp, mid, end);
		merge(a, tmp, start, mid, end);
	}
}









