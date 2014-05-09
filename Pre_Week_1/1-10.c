/**
*直接插入排序/折半插入排序/希尔排序/快速排序（非递归）
*/
#include<stdio.h>
//直接插入排序
void straight_insert_Sort(int a[], const int start, const int end);
//折半插入排序
void binary_insert_Sort(int a[], const int start, const int end);
//希尔排序
void shell_Sort(int a[], const int start, const int end);
//快速排序（非递归）
void quick_Sort(int a[], const int start, const int end);

void display(int a[], int n);

int main(){
	int a[11] = {0, 9, 8, 6, 4, 1, 10, 19, 16, 5, 7};
	display(a, 11);
	quick_Sort(a, 0, 11);
	display(a, 11);
return 0;
}

void straight_insert_Sort(int a[], const int start, const int end){
	int i, j;
	for(i = start + 1; i <= end; i++){
		a[0] = a[i];
		for(j = i - 1; j >= start && a[j] > a[0]; j--){
				a[j + 1] = a[j];
		}
		a[j + 1] = a[0];
	}
}

void binary_insert_Sort(int a[], const int start, const int end){
	int i, j, mid, m, n;
	for(i = start + 1; i <= end; i++){
		a[0] = a[i];
		m = start; n = i;
		while(m <= n){
			mid = (m + n) / 2;
			if(a[mid] > a[0]){
				n = mid - 1;
			}
			else{
				m = mid + 1;
			}
		}
		for(j = i; j > m; j--){
			a[j] = a[j - 1];
		}
		a[j] = a[0];
	}
}
//1-11 update
void shell_Sort(int a[], const int start, const int end){
	int step, i, j, temp;
	step = end - start;
	while(step > 1){
		step = step / 3 + 1;
		for(i = start + step; i < end; i++){
			temp = a[i];
			for(j = i - step; j >= start && a[j] > temp; j = j - step){
				a[j + step] = a[j];
			}
			a[j + step] = temp;
		}
	}
}
//1-11 update //有借鉴于网络//还需加深理解
void quick_Sort(int a[], const int start, const int end){
	int stack[100];
	int top = 0;
	int low, high, i, j, pivot;
	int temp;
	stack[top++] = (end - start);
	stack[top++] = 0;
	while(top != 0){
		low = stack[--top];
		high = stack[--top];
		pivot = high;
		i = low;
		for(j = low; j < high; j++){
			if(a[j] <= a[pivot]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				i++;
			}
		}
		if(i != pivot){
			temp = a[i];
			a[i] = a[pivot];
			a[pivot] = temp;
		}	
		if(i - low > 1){
			stack[top++] = i - 1;
			stack[top++] = low;
		}
		if(high - i > 1){
			stack[top++] = high;
			stack[top++] = i + 1;
		}
	}	
}

void display(int a[],int n){
	int i = 0;
	while(i < n) {
		printf("%d --> %d \n", i, a[i]), i++;
	}
}
