#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
} LinkNode, *Linklist;

void init_list(Linklist *L);//����ͷ���@

void create_list_head(Linklist L, int *input, int len);//��������ͷ�巨��@

void create_list_tail(Linklist L, int *input, int len);//��������β�巨��@

void insert_element(Linklist L, int pos, int insert);//��posλ�ò���insert @

void delete_element(Linklist L, int pos);//ɾ��posλ�õ�Ԫ��@

int get_length(Linklist L);//ȡ������@

int is_empty(Linklist L);//�ж������Ƿ�Ϊ��@

void get_value(Linklist L, int pos, int *get);//ȡ��posλ�õ�Ԫ�ش���get@

void set_value(Linklist L, int pos, int set);//��posλ�õ�Ԫ�ظ�ֵΪset@

void debug(Linklist L);//��ӡ�������Ԫ��@

void reverse(Linklist L);//��������@

void clear(Linklist L);//����������ݽڵ�@

void destory(Linklist *L);//������������@

void merge_tail(Linklist L, Linklist src1, Linklist src2);//�ϲ���������@

void merge_head(Linklist L, Linklist src1, Linklist src2);//�ϲ���������@

#endif
