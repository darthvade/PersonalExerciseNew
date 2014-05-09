#include "head_prog.h"

int Myadd(int a, int b) {
	return a + b;
}
int Mysub(int a, int b) {
	return a - b;
}
int Mymax(int a, int b) {
	return a > b ? a : b;
}
int Mymin(int a, int b) {
	return a > b ? b : a;
}

void testFunPointer() {
	int a = 3;
	int b = 6;
	int input;
	while(scanf("%d", &input) == 1) {
		int (*p)(int a, int b);
		system("cls");
		switch(input) {
			case 1:
				p = &Myadd;
				printf("%d\n", (*p)(a, b));
				break;
			case 2:
				p = &Mysub;
				printf("%d\n", (*p)(a, b));
				break;
			case 3:
				p = &Mymax;
				printf("%d\n", (*p)(a, b));
				break;
			case 4:
				p = &Mymin;
				printf("%d\n", (*p)(a, b));
				break;
			default:
				printf("input error!");
				break;
		}
	}
}

void MutiMatrix(int a[][2], int b[][3], int c[][3]) {
	int i, j;
	int k;
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 3; j++) {
			c[i][j] = 0;
			for(k = 0; k < 2; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}

void Bubble_sort(Student *input, const int start, const int end, int (*cmp)(Student *a, Student *b)) {
	int i, j, exchange;
	for(i = 0; i < end; i++) {
		exchange = 0;
		for(j = end - 1; j > i; j--) {
			if(cmp(input + j, input + j - 1) < 0) {
				swap(input + j, input + j - 1);
				exchange = 1;
			}
		}
		if(exchange == 0) {
			return;
		} 
	}
}

void swap(Student *a, Student *b) {
	Student temp;
	studentcpy(&temp, a);
	studentcpy(a, b);
	studentcpy(b, &temp);
}

void studentcpy(Student *dent, Student *src) {
	(*dent).age = (*src).age;
	(*dent).num = (*src).num;
	strcpy(dent->name, src->name);
}

void printstudent(const Student *s, const int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("num:%d --> age:%d --> name:%s\n", s[i].num, s[i].age, s[i].name);
	}
	putchar('\n');
}

int cmp(Student *a, Student *b) {
	//return a->num > b->num ? 1 : -1;
	return strcmp(a->name, b->name);
	//return a->age > b->age ? 1 : -1;
}