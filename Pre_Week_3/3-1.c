/**
* linklist
*/
#include<stdlib.h>
#include<stdio.h>

#define false -1
#define true 1

typedef int elem_t;

typedef struct LNode {
	elem_t data;
	struct LNode *next;
} LNode;

void init_list(LNode **l);

void insert_head(LNode *l, elem_t e);
	
LNode *search(LNode *l, int pos);

void delete(LNode *l, int pos);

int reverse(LNode *l);//链表逆置

void print(LNode *l);

int main() {
	LNode *list;
	init_list(&list);
	insert_head(list, 5);
	insert_head(list, 6);
	insert_head(list, 2);
	insert_head(list, 9);
	insert_head(list, 7);
	insert_head(list, 3);
	print(list);
	reverse(list);
	print(list);
	return 0;
}

void init_list(LNode **l) {
	*l = (LNode*)malloc(sizeof(LNode));
	(*l)->data = 0;
	(*l)->next = NULL;
}

void insert_head(LNode *l, elem_t e) {
	LNode *tmp = (LNode*)malloc(sizeof(LNode));
	tmp->data = e;
	tmp->next = NULL;
	if(l->next == NULL) {
		l->next = tmp;
		(l->data)++;
	}
	else {
		tmp->next = l->next;
		l->next = tmp;
		(l->data)++;
	}
}
	
LNode *search(LNode *l, int pos) {
	LNode *tmp = l;
	int i = 0;
	while(i != pos && tmp != NULL) {
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

void delete(LNode *l, int pos) {
	LNode *del = search(l, pos - 1);
	LNode *tmp = del->next;
	del->next = tmp->next;
	free(tmp);	
}

void print(LNode *l) {
	LNode *tmp = l;
	int i = 0;
	while(tmp->next != NULL) {
		i++;
		tmp = tmp->next;
		printf("%d --> %d\n", i, tmp->data);
	}
	printf("\n");
}

int reverse(LNode *l) {
	if(l == NULL) {
		return false;
	}
	if(l->next == NULL || l->next->next == NULL) {
		return true;
	}
	LNode *pos = l->next->next;
	LNode *tmp = pos;
	l->next->next = NULL;
	while(pos != NULL) {
		pos = pos->next;
		tmp->next = l->next;
		l->next = tmp;
		tmp = pos;	
	}
}
