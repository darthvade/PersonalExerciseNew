/**
C语言结构题练习
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Student {
	int id;
	float score;
} Student;//结构体声明

void init(Student stu[], int n);//初始化结构体数组

void print(Student stu[], int n);//打印结构体数组

void BubbleSort(Student stu[], int n);//冒泡排序

void QuickSort(Student stu[], int i, int j);//快速排序

void SeqSearch(Student stu[], int n, float score);//顺序查找

void BinarySearch(Student stu[], int n, float score);//折半查找

void swap(Student* a, Student* b);

int position(Student stu[], int i, int j);

int main(int argc, char* argv[]) {
	Student stu[10];
	init(stu, 10);
	SeqSearch(stu, 10, 64.9);
	QuickSort(stu, 0, 9);
	print(stu, 10);
	BinarySearch(stu, 10, 79.3);
	return 0;
}

void init(Student stu[],int n){
	 int i = 0;
     for(; i < n; i++){
     	stu[i].id = i;
     	stu[i].score = (float)(rand() % 1000) / 10;
     }
}

void print(Student stu[], int n){
	int i = 0;
	for(; i < n; i++) {
		printf("Id:%d__Score:%.1f\n", stu[i].id, stu[i].score);
	}	
}

void BubbleSort(Student stu[], int n){
	int i, j;
	int flag = 1;
	for(i = 0; i < n && flag; i++) {
		for(j = 0; j < n - i - 1; j++){
			flag = 0;
			if(stu[j].score > stu[j+1].score) {
				swap(&stu[j], &stu[j+1]);
				flag = 1;
			}
		}
	}
}

void QuickSort(Student stu[], int i, int j){
	if(i < j){
		int pos = position(stu, i, j);
		QuickSort(stu, i, pos - 1);
		QuickSort(stu, pos + 1, j);
	}
}

int position(Student stu[], int i, int j){
	Student temp;
	temp = stu[i];
	while(i < j){
		while(stu[j].score > temp.score && i < j) j--;
		stu[i] = stu[j];
		while(stu[i].score < temp.score && i < j) i++;
		stu[j] = stu[i];
	}
	stu[i] = temp;
	return i;
}

void swap(Student* a, Student* b) {
	Student temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SeqSearch(Student stu[],int n, float score){
	int i;
	for(i = 0; i < n; i++){
		if(score == stu[i].score){
			printf("The ID is %d\n", stu[i].id);
		}
	}
}

void BinarySearch(Student stu[], int n, float score){
	int i = 0, j = n - 1;
	while(i < j){
		if(stu[(i + j) / 2].score == score) {
			i = (i + j) / 2;
			break;
		}
		else if(stu[(i + j) / 2].score > score) {
			j = (i + j) / 2 - 1;
		}
		else{
			i = (i + j) / 2 + 1;
		}
	}
	printf("The ID is %d\n", stu[i].id);
}



















