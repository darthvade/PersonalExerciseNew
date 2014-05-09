#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
} LinkNode, *Stack;

void init_stack(Stack *s);//初始化栈@
void destory_stack(Stack *s);//销毁栈@
void clear(Stack s);//清空栈元素@

int is_empty(Stack s);//判断栈是否为空@
void push(Stack s, int data);//进栈@
int pop(Stack s, int *data);//出栈@

int top(Stack s, int *data);//返回栈顶元素@

void debug(Stack L);//输出栈中所有元素

#endif