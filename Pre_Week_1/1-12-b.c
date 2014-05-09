/**
*线性表的链式存储
*/

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
//存储结构定义
typedef struct LNode {
	Elemtype data;
	struct LNode *next;
} LNode, *LinkList;


LNode* InitList_head();//初始化链表（头插法）

LNode* InitList_rear();//初始化链表（尾插法）

LNode* GetElem(LinkList l, int i);//按序号查找结点

LNode* LocateElem(LinkList l, Elemtype e);//按值查找结点

int InsertNode(LinkList l, int i, Elemtype e);//在指定位置插入结点

int DeleteNode(LinkList l, int i);//删除指定位置结点

void Traversal(LinkList l);

int main() {
	LinkList ls;
	ls = InitList_rear();
	Traversal(ls);
	/*
	LinkList find;
	find = GetElem(ls, 3);
	printf("%d\n", find->data);
	find = LocateElem(ls, 111);
	printf("%d\n", find->data);
	*/
	InsertNode(ls, 5, 111);
	Traversal(ls);
	DeleteNode(ls, 1);
	Traversal(ls);
	return 0;
}


LNode* InitList_head(){
	LNode *s, *l;
	int x;
	l = (LinkList)malloc(sizeof(LNode));
	l->next = NULL;
	scanf("%d", &x);
	while(x != 9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = l->next;
		l->next = s;
		scanf("%d", &x);
	}
	return l;
}//初始化链表（头插法）

LNode* InitList_rear(){
	LNode *s, *r, *l;
	int x;
	l = (LinkList)malloc(sizeof(LNode));
	r = l;
	l->next = NULL;
	scanf("%d", &x);
	while(x != 9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	return l;
}//初始化链表（尾插法）

LNode* GetElem(LinkList l, int i){
	LNode *s = l;
	while(i >= 0){
		s = s->next;
		i--;
	}
	return s;
}//按序号查找结点

LNode* LocateElem(LinkList l, Elemtype e){
	LNode *s = l;
	while(s->next != NULL){
		if(s->data == e){
			return s;
		}else{
			s = s->next;
		}
	}
}//按值查找结点

int InsertNode(LinkList l, int i, Elemtype e){
	LNode *s, *insert;
	s = GetElem(l, i - 1);
	insert = (LNode *)malloc(sizeof(LNode));
	insert->data = e;
	insert->next = s->next;
	s->next = insert;
	return 1;
}//在指定位置插入结点

int DeleteNode(LinkList l, int i){
	LNode *s, *delete;
	s = GetElem(l, i - 1);
	delete = s->next;
	s->next = delete->next;
	free(delete);
	return 1;
}//删除指定位置结点

void Traversal(LinkList l){
	LNode *s = l;
	int i = 0;
	while(s->next) {
		printf("%d-->%d\n", i, s->next->data);
		i++;
		s = s->next;
	}
	printf("\n");
}



