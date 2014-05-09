#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define N 20

void setCircleArr(int matrix[][N], int start, int end, int *count);

int main() {

	//输出已输入的所有行中的最长行 (拷贝版) 
	/*char input[200];
	char longest[200];
	int len_max = 0;
	int len_temp = 0;
	while(gets(input)) {
		len_temp = strlen(input);
		if(len_temp > len_max) {
			len_max = len_temp;
			strcpy(longest, input);
		}
	}
	printf("The longest line is :\n%s\n", longest);*/


	//输出已输入的所有行中的最长行 （非拷贝版）
	/*char input1[200];
	char input2[200];
	int len_max = 0;
	int len_temp = 0;
	char *temp;
	char *longest;
	temp = input1;
	while(gets(temp)) {
		len_temp = strlen(temp);
		if(len_temp > len_max) {
			len_max = len_temp;
			longest = temp;
			temp = (temp != input1 ? input1 : input2);
		}
	}
	printf("The longest line is :\n%s\n", longest);*/


	//打印菱形
	/*int n;
	int i;
	int j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n - i; j++) {
			putchar(' ');
		}
		while(j <= n){
			printf("* ");
			j++;
		}
		putchar('\n');
	}
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			putchar(' ');
		}
		while(j <= n){
			printf("* ");
			j++;
		}
		putchar('\n');
	}*/


	//打印空菱形
	/*int n;
	int i;
	int j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n - i; j++) {
			putchar(' ');
		}
		while(j <= n){
			if(j == (n - i + 1)) {
				printf("* ");
			} else if (j == n){
				printf("* ");
			} else {
				printf("  ");
			}
			j++;
		}
		putchar('\n');
	}
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			putchar(' ');
		}
		while(j <= n){
			if(j == i + 1) {
				printf("* ");
			} else if (j == n){
				printf("* ");
			} else {
				printf("  ");
			}
			j++;
		}
		putchar('\n');
	}*/


	//打印乘法表
	/*int i;
	int j;
	for(i = 1; i <= 9; i++) {
		for(j = 1; j <= i; j++) {
			printf("%d*%d=%2d ", i, j, i*j);
			if(j == i) {
				putchar('\n');
			}
		}
	}*/

	//打印螺旋数组(外到内，顺时针)
	/*int matrix[N][N];
	int i, j;
	int count = 1;
	int circle;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			matrix[i][j] = 0;
		}
	}
	circle = (N / 2) + 1;
	for(i = 0; i < circle; i++) {
		setCircleArr(matrix, i, N - i - 1, &count);
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}*/

	system("pause");
	return 0;
}

void setCircleArr(int matrix[][N], int start, int end, int *count) {
	int i;
	int j;
	if(start == end) {
		matrix[start][end] = (*count)++;
	}
	for(i = start, j = start; j < end; j++) {
		matrix[i][j] = (*count)++;
	}
	for(j = end, i = start; i < end; i++) {
		matrix[i][j] = (*count)++;
	}
	for(i = end, j = end; j > start; j--) {
		matrix[i][j] = (*count)++;
	}
	for(j = start, i = end; i > start; i--) {
		matrix[i][j] = (*count)++;
	}
}