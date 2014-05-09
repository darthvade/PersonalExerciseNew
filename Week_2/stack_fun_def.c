#include "stack.h"

void init_stack(Stack *s) {
	(*s) = (LinkNode *)malloc(sizeof(LinkNode));
	(*s)->data = 0;
	(*s)->next = NULL;
}//初始化栈@

void destory_stack(Stack *s) {
	if((*s)->next != NULL) {
		clear(*s);
	}
	free(*s);
	*s = NULL;
}//销毁栈@

void clear(Stack s) {
	LinkNode *tmp = s->next;
	while(tmp) {
		s->next = tmp->next->next;
		free(tmp);
		tmp = s->next;
	}
}//清空栈元素@

int is_empty(Stack s) {
	if(s->next == NULL) {
		return 1;
	} else {
		return 0;
	}
}//判断栈是否为空@

void push(Stack s, int data) {
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = data;
	p->next = NULL;
	p->next = s->next;
	s->next = p;
}//进栈

int pop(Stack s, int *data) {
	LinkNode *p = s->next;
	if(s->next == NULL) {
		printf("Error! No elements in this stack!\n");
		return -1;
	}
	*data = p->data;
	s->next = p->next;
	free(p);
	return 1;
}//出栈

int top(Stack s, int *data) {
	if(s->next == NULL) {
		printf("Error! No elements in this stack!\n");
		return -1;
	}
	*data = s->next->data;
	return 1;
}//返回栈顶元素

void debug(Stack L) {
	int i = 0;
	LinkNode *p;
	if(L == NULL) {
		printf("This stack is not existed!\n");
		return;
	}
	p = L->next;
	if(L->next == NULL) {
		printf("No element in this stack!\n");
	}
	while(p) {
		printf("No.%d --> %d\n", i, p->data);
		p = p->next;
		i++;
	}
	putchar('\n');
}//打印输出所有元素