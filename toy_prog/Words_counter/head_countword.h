#ifndef _COUNTWORD_
#define _COUNTWORD_
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ARRAY_MAX_SIZE 1000000 //单词数组最大值
#define WORD_MAX_SIZE 200 //单词最大长度
#define SEED_HASH 31 //哈希种子

//哈希表元素
typedef struct Node {
	struct Node *next;
	int count;
	char *word;
}Node;

//哈希数组
Node hasharray[ARRAY_MAX_SIZE];

//词频排序数组
Node sortarray[ARRAY_MAX_SIZE];

//单词数组
char input[ARRAY_MAX_SIZE][WORD_MAX_SIZE];

//从文件获取单词放到单词数组中并统计总词数
void getWords(char *filename, char input[][WORD_MAX_SIZE], int *array_size);

//取得每个单词的哈希码
unsigned int getHashCode(char *str);

//统计单词词频，链表发处理冲突，【有问题】
void countWords(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size);

//统计单词词频，线性探测法，【已实现】
void countWords_linear(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size, int *unique_words_num);

//遍历哈希数组,并存储元素到词频排序数组
void trverseHashArray(Node *hasharray, Node *sortarray, const int hasharray_size, int *unique_words_num);

//遍历哈希数组,并存储元素到词频排序数组(线性探测版)
void trverseHashArray_linear(Node *hasharray, Node *sortarray, const int hasharray_size);

//快速排序
void quicksort(Node *sortarray, const int start, const int end);
int partition(Node *sortarray, const int start, const int end);

//折半插入排序
void binary_insertion_sort(Node *sortarray, const int start, const int end);

//输出词频前N高的单词及其词频
void printTopN_frequence(Node *sortarray, const int unique_words_num, int topn);

//替换文件中的标点符号并生成新文件
void replace_punctuation(char *filename, char *newfile, char replace);

#endif