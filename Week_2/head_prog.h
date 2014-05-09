#ifndef _HEAD_
#define _HEAD_
#include <stdio.h>
#include <Windows.h>
#include <string.h>

int Myadd(int a, int b);
int Mysub(int a, int b);
int Mymax(int a, int b);
int Mymin(int a, int b);

typedef struct Student {
	int num;
	char name[20];
	int age;
} Student;

void testFunPointer();

void MutiMatrix(int a[][2], int b[][3], int c[][3]);

void Bubble_sort(Student *input, const int start, const int end, int (*cmp)(Student *a, Student *b));

void swap(Student *a, Student *b);

void studentcpy(Student *dent, Student *src);

void printstudent(const Student *s, const int n);

int cmp(Student *a, Student *b);

#endif