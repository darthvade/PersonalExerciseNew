#ifndef _HEAD_H_
#define _HEAD_H_
#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>

void quick_sort(int *input, const int start, const int end);//��������

int partition(int *input, const int start, const int end);//��������Ļ��ֲ���@

//void swap(int *a, int *b);

int topk(int *input, int k, int len);//Ѱ����������input�е�k�����

int factorial(int n);//n�Ľ׳�

int fibonacci(int n);//fibonacci����

int fibonacci_v2(int *input, int n);//fibonacci����

#endif
