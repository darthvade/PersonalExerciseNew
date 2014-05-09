#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
} LinkNode, *Linklist;

void init_list(Linklist *L);//建立头结点@

void create_list_head(Linklist L, int *input, int len);//建立链表（头插法）@

void create_list_tail(Linklist L, int *input, int len);//建立链表（尾插法）@

void insert_element(Linklist L, int pos, int insert);//在pos位置插入insert @

void delete_element(Linklist L, int pos);//删除pos位置的元素@

int get_length(Linklist L);//取得链表长@

int is_empty(Linklist L);//判断链表是否为空@

void get_value(Linklist L, int pos, int *get);//取得pos位置的元素存入get@

void set_value(Linklist L, int pos, int set);//对pos位置的元素赋值为set@

void debug(Linklist L);//打印输出所有元素@

void reverse(Linklist L);//链表逆置@

void clear(Linklist L);//清除所有数据节点@

void destory(Linklist *L);//销毁整个链表@

void merge_tail(Linklist L, Linklist src1, Linklist src2);//合并两个链表@

void merge_head(Linklist L, Linklist src1, Linklist src2);//合并两个链表@

#endif
