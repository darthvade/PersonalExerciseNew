/**
*	基本思想：将所有字符串存储在一个结构体数组里，从第一个串开始，
*			  找出这个字符串的所有母串，之后依次打印该字符串和其所有母串；
*			  之后，从第二个字符串开始，以此类推，直到打印出所有字符串
*			  *注：字符串长度为1组的直接打印，不许要找母串
*/

#include<stdio.h>
#include<string.h>

typedef struct {
	int n;		//存储一条编码中的组数
	char name[16];	//存储组的名字
	char code[64];	//存储编码
	int isPre;	//存储一条编码是否为另一条编码的前缀：若是，其值为1；不是，其值为0
	int isCode;	//本单元是否存储着一条编码：值为1，为有；值为0，为没有
	int printed;    //记录一条编码是否被打印过：值为1，为打印过；值为0，为没打印过
} Decode; 

int isPrefix(const char* s1, const char* s2);//s2是否是s1的前缀：若是，返回1；不是，返回0

void initArray(Decode* dc, int n);//初始化结构体数组dc,数组大小为n 

void readFile(const char* fname, Decode* dc);//读取文件fname到结构体数组dc

void printArray(Decode* dc);//按模式打印结构体数组dc

int main(){
	
	Decode dc[20];
	initArray(dc, 20);
	readFile("input.txt", dc);
	printArray(dc);
	
	/**测试readFile
	printf("%s\n", dc[16].name);//测试用
	printf("%s\n", dc[16].code);//测试用
	*/
	///*
	/**测试isPrefix
	char* str1 = "002";
	char* str2 = "001003004";
	printf("%d\n", isPrefix(str1, str2));
	*/
	return 0;
}

int isPrefix(const char* s1, const char* s2){
	if(s1 == NULL || s2 == NULL){
		return 0;
	}
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int i = 0;
	while((l2 < l1) && (i < l2) && (s1[i] == s2[i])){
		i++;
	}
	if(i == l2){
		return 1;
	}else{
		return 0;
	}
}

void initArray(Decode* dc, int n){
	int i = 0;
	while(i < n){
		dc[i].n = 0;
		strcpy(dc[i].name, "");
		strcpy(dc[i].code, "");
		dc[i].isPre = 0;
		dc[i].isCode = 0;
		dc[i].printed = 0;
		i++;
	}
}

void readFile(const char* fname, Decode* dc){
	char code[64];
	char name[16];
	int i = 0;
	FILE* fin;
	fin = fopen(fname, "rb");
	while(fscanf(fin, "%s%s", code, name) != EOF){
		strcpy(dc[i].code, code);
		strcpy(dc[i].name, name);
		dc[i].isCode = 1;
		dc[i].n = strlen(code) / 3;
		i++;
	//	printf("%s\n", dc[i - 1].code);//测试用
	//	printf("%s\n", dc[i - 1].name);//测试用
	//	printf("%d\n", dc[i - 1].n);//测试用
	}
	fclose(fin);	
}

void printArray(Decode* dc){
	int i = 0;
	int j = 0;
	int n = 0;
	while(dc[i].isCode){
		if(1 == dc[i].n){
			printf("%s\n", dc[i].name);
			i++;
		}else{
			dc[i].isPre = 1;
			j = i + 1;
			//while扫描一遍数组，确定dc[i].code是哪些字符串的子串
			while(dc[j].isCode){
				dc[j].isPre = isPrefix(dc[j].code, dc[i].code);
				j++;
			}
			j = i;
			//打印哪些未被打印过的dc[i].code的母串
			while(dc[j].isCode){
				if(dc[j].isPre && !dc[j].printed) {
					n = dc[j].n - 1;
					while(n--){
						printf("%s", "    ");
					}
					printf("%s\n", dc[j].name);
					dc[j].isPre = 0;
					dc[j].printed = 1;
				}
				j++;
			}
			i++;
		}
	}
}

void printArray_v2(Decode* dc){
	int i = 0;
	int j = 0;
	int n = 0;
	while(dc[i].isCode){
		if(1 == dc[i].n){
			printf("%s\n", dc[i].name);
			i++;
		}else{
			dc[i].isPre = 1;
			j = 0;
			//while扫描一遍数组，确定dc[i].code是哪些字符串的子串
			while(dc[j].isCode){
				dc[j].isPre = isPrefix(dc[j].code, dc[i].code);
				j++;
			}
			j = 0;
			//打印哪些未被打印过的dc[i].code的母串
			while(dc[j].isCode){
				if(dc[j].isPre && !dc[j].printed) {
					n = dc[j].n - 1;
					while(n--){
						printf("%s", "    ");
					}
					printf("%s\n", dc[j].name);
					dc[j].isPre = 0;
					dc[j].printed = 1;
				}
				j++;
			}
			i++;
		}
	}
}




