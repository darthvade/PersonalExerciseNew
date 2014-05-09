#ifndef _HEAD_H_
#define _HEAD_H_
#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>

void quick_sort(int *input, const int start, const int end);//快速排序

int partition(int *input, const int start, const int end);//快速排序的划分操作@

//void swap(int *a, int *b);

int topk(int *input, int k, int len);//寻找有序数组input中第k大的数

int factorial(int n);//n的阶乘

int fibonacci(int n);//fibonacci数列

int fibonacci_v2(int *input, int n);//fibonacci数列

#endif
