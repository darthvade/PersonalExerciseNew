#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<math.h>

int count_bits(long long int n);

int main() {
	//打印行数
	/*int i = 1;
	char arr[100];
	while(1) {
		gets(arr);
		printf("%d -> %s\n", i++, arr);
	}*/

	/*int a, b;
	int c;
	c = scanf("%d %d", &a, &b);
	printf("%d %d %d\n", a, b, c);
	system("pause");*/
	
	//sizeof实验
	/*
	char c;
	int i;
	float f;
	double d;

	char *pc;
	int *pi;
	float  *pf;
	double *pd;

	char arr1[] = "Hello";
	char arr2[10];
	double arr3[10];

	printf("char --> %d\n", sizeof(c));
	printf("int --> %d\n", sizeof(i));
	printf("float --> %d\n", sizeof(f));
	printf("double --> %d\n", sizeof(d));
	printf("char * --> %d\n", sizeof(pc));
	printf("int * --> %d\n", sizeof(pi));
	printf("float * --> %d\n", sizeof(pf));
	printf("double * --> %d\n", sizeof(pd));
	printf("char [] --> %d\n", sizeof(arr1));
	printf("char [10]--> %d\n", sizeof(arr2));
	printf("double [10] --> %d\n", sizeof(arr3));
	*/

	//大写字母转小写
	/*char input[100];
	int i;
	int len;
	while(1) {
		gets(input);
		len = sizeof(input) / sizeof(char);
		for(i = 0; i < len; i++) {
			if(input[i] >= 'A' && input[i] <= 'Z') {
				input[i] = input[i] + 'a' - 'A';
			}
		}
		puts(input);
	}*/

	//统计字符、数字和其他字符数
	/*char input[100];
	int i;
	int len;
	int count_char;
	int count_num;
	int count_other;
	while(1) {
		count_char = 0;
		count_num = 0;
		count_other = 0;
		gets(input);
		len = strlen(input);
		for(i = 0; i < len; i++) {
			if((input[i] >= 'A' && input[i] <= 'Z')) {
				count_char++;
			} else if (input[i] >= 'a' && input[i] <= 'z') {
				count_char++;
			} else if(input[i] >= '0' && input[i] <= '9') {
				count_num++;
			} else {
				count_other++;
			}
		}
		printf("count_char : %d\n", count_char);
		printf("count_num : %d\n", count_num);
		printf("count_other : %d\n", count_other);
	}*/

	//统计字符串中单词个数
	/*char input[100];
	int count_word;
	int len;
	int pos;
	while(1) {
		gets(input);
		count_word = 0;
		len = strlen(input);
		if(input[0] != ' ') {
			pos = 1;
		} else {
			pos = 0;
		}
		for(; pos < len; pos++) {
			if(input[pos] == ' ') {
				continue;
			}
			if((input[pos] >= 'A' && input[pos] <= 'Z') && input[pos + 1] == ' ') {
				count_word++;
			} else if((input[pos] >= 'a' && input[pos] <= 'z') && input[pos + 1] == ' ') {
				count_word++;
			}
		} 
		if((input[len] == 0) && (input[len - 1] != ' ')) {
			count_word++;
		}
		if(len == 0) {
			count_word = 0;
		}
		printf("count_word: %d\n", count_word);
	}*/
	
	//统计字符串中单词个数（scanf版）
	/*char input[100];
	int count_word = 0;
	while(scanf("%s", input) != -1) {
		count_word++;
	}
	printf("count_word: %d", count_word);*/

	//计算一个整型数的位数
	/*long long int input;
	int count_bit = 1;
	scanf("%lld", &input);
	while((input / 10) != 0) {
		count_bit++;
		input = input / 10;
	}
	printf("count_bits : %d\n", count_bit);*/

	//倒置一个整数
	int bits;
	long long int input;
	long long int output = 0;
	int sum[200];
	long long int base[200];
	int i;
	scanf("%lld", &input);
	printf("original : %lld\n", input);
	bits = count_bits(input);
	for(i = 0; i < bits; i++) {
		base[i] = pow(10, i);
	}
	for(i = 0; i < bits; i++) {
		sum[i] = input / base[bits - i - 1];
		input = input % base[bits - i - 1];
	}
	for(i = 0; i < bits; i++) {
		output = output + sum[bits - i - 1] * base[bits - i - 1];
	}
	printf("reversed : %lld\n", output);

	system("pause");
	return 0;
}

int count_bits(long long int n) {
	int count_bit = 1;
	while((n / 10) != 0) {
		count_bit++;
		n = n / 10;
	}
	return count_bit;
}