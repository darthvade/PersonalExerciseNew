#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
} LinkNode, *Stack;

void init_stack(Stack *s);//��ʼ��ջ@
void destory_stack(Stack *s);//����ջ@
void clear(Stack s);//���ջԪ��@

int is_empty(Stack s);//�ж�ջ�Ƿ�Ϊ��@
void push(Stack s, int data);//��ջ@
int pop(Stack s, int *data);//��ջ@

int top(Stack s, int *data);//����ջ��Ԫ��@

void debug(Stack L);//���ջ������Ԫ��

#endif