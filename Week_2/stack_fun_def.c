#include "stack.h"

void init_stack(Stack *s) {
	(*s) = (LinkNode *)malloc(sizeof(LinkNode));
	(*s)->data = 0;
	(*s)->next = NULL;
}//��ʼ��ջ@

void destory_stack(Stack *s) {
	if((*s)->next != NULL) {
		clear(*s);
	}
	free(*s);
	*s = NULL;
}//����ջ@

void clear(Stack s) {
	LinkNode *tmp = s->next;
	while(tmp) {
		s->next = tmp->next->next;
		free(tmp);
		tmp = s->next;
	}
}//���ջԪ��@

int is_empty(Stack s) {
	if(s->next == NULL) {
		return 1;
	} else {
		return 0;
	}
}//�ж�ջ�Ƿ�Ϊ��@

void push(Stack s, int data) {
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = data;
	p->next = NULL;
	p->next = s->next;
	s->next = p;
}//��ջ

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
}//��ջ

int top(Stack s, int *data) {
	if(s->next == NULL) {
		printf("Error! No elements in this stack!\n");
		return -1;
	}
	*data = s->next->data;
	return 1;
}//����ջ��Ԫ��

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
}//��ӡ�������Ԫ��