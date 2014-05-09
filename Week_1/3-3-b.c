/**
* 编程之美 2.1-求二进制数中1的个数
*/
#include<stdio.h>
typedef unsigned char BYTE;

int Count_V1(BYTE v);
int Count_V2(BYTE v);
int Count_V3(BYTE v);

int main() {
	BYTE b = 255;
	//printf("%d\n", sizeof(b));
	printf("Count: %d\n", Count_V3(b));
	return 0;
}

int Count_V1(BYTE v) {
	int num = 0;
	while(v) {
		if((v % 2) == 1) {
			num++;
		}
		v = v / 2;
	}
	return num;
}

int Count_V2(BYTE v) {
	int num = 0;
	while(v) {
		num = num + (v & 0x01);
		v = v >> 1;
	}
	return num;
}

int Count_V3(BYTE v) {
	/*
		任意一个二进制数例如 10101000  
		其减去一为			 10100111
		上下按位与，得		 10100000     注意：正好可以消去最后一个一
		以此类推，统计所有一的个数
	*/
	int num = 0;
	while(v) {
			v = v & (v - 1);
			num++;
		}
	return num;
}
