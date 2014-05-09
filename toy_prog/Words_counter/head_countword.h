#ifndef _COUNTWORD_
#define _COUNTWORD_
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ARRAY_MAX_SIZE 1000000 //�����������ֵ
#define WORD_MAX_SIZE 200 //������󳤶�
#define SEED_HASH 31 //��ϣ����

//��ϣ��Ԫ��
typedef struct Node {
	struct Node *next;
	int count;
	char *word;
}Node;

//��ϣ����
Node hasharray[ARRAY_MAX_SIZE];

//��Ƶ��������
Node sortarray[ARRAY_MAX_SIZE];

//��������
char input[ARRAY_MAX_SIZE][WORD_MAX_SIZE];

//���ļ���ȡ���ʷŵ����������в�ͳ���ܴ���
void getWords(char *filename, char input[][WORD_MAX_SIZE], int *array_size);

//ȡ��ÿ�����ʵĹ�ϣ��
unsigned int getHashCode(char *str);

//ͳ�Ƶ��ʴ�Ƶ�����������ͻ���������⡿
void countWords(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size);

//ͳ�Ƶ��ʴ�Ƶ������̽�ⷨ������ʵ�֡�
void countWords_linear(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size, int *unique_words_num);

//������ϣ����,���洢Ԫ�ص���Ƶ��������
void trverseHashArray(Node *hasharray, Node *sortarray, const int hasharray_size, int *unique_words_num);

//������ϣ����,���洢Ԫ�ص���Ƶ��������(����̽���)
void trverseHashArray_linear(Node *hasharray, Node *sortarray, const int hasharray_size);

//��������
void quicksort(Node *sortarray, const int start, const int end);
int partition(Node *sortarray, const int start, const int end);

//�۰��������
void binary_insertion_sort(Node *sortarray, const int start, const int end);

//�����ƵǰN�ߵĵ��ʼ����Ƶ
void printTopN_frequence(Node *sortarray, const int unique_words_num, int topn);

//�滻�ļ��еı����Ų��������ļ�
void replace_punctuation(char *filename, char *newfile, char replace);

#endif