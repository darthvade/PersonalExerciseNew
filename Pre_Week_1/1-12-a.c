/**
*线性表的具体实现（顺序存储）
*/

#include<stdio.h>

//存储结构声明
#define MaxSize 100
#define Elemtype int
typedef struct {
	Elemtype data[MaxSize];
	int length;
} SqList;

//基本操作声明
void InitList(SqList *list);//初始化线性表

int Length(SqList *list);//求表长,返回表长

int LocateElem(SqList *list, Elemtype e);//按‘值’查找元素，返回其下标

Elemtype GetElem(SqList *list, int i);//按‘位置’查找元素，返回其值

int ListInsert(SqList *list, int i, Elemtype e);//在i位置插入元素e

int ListDelete(SqList *list, int i);//删除表中i位置的元素

void PrintList(SqList *list);//顺序输出所有元素值

int Empty(SqList *list);//表判空操作

int main() {
	SqList list;
	InitList(&list);
	ListInsert(&list, 0, 99);
	ListInsert(&list, 1, 89);
	ListInsert(&list, 2, 79);
	ListInsert(&list, 3, 69);
	ListInsert(&list, 4, 59);
	PrintList(&list);
	printf("length = %d\n", Length(&list));
	ListDelete(&list, 3);
	printf("length = %d\n", Length(&list));
	PrintList(&list);
	printf("elem = %d\n", GetElem(&list, 2));
	printf("empty = %d\n", Empty(&list));
	return 0;
}

void InitList(SqList *list){
	list->length = 0;	
}//初始化线性表

int Length(SqList *list){
	return list->length;
}//求表长,返回表长

int LocateElem(SqList *list, Elemtype e){
	int i;
	for(i = 0; i < list->length; i++){
		if(list->data[i] == e){
			return i;
		}
	}
	return 0;
}//按‘值’查找元素，返回其下标

Elemtype GetElem(SqList *list, int i){
	return list->data[i];
}//按‘位置’查找元素，返回其值

int ListInsert(SqList *list, int i, Elemtype e){
	int j;
	if(i < 0 || i > list->length){
		return 0;
	}
	for(j = list->length; j < list->length - i; j--){
		list->data[j + 1] = list->data[j];
	}
	list->data[i] = e;
	list->length++;
	return 1;
}//在i位置插入元素e

int ListDelete(SqList *list, int i){
	int j;
	if(i < 0 || i > list->length){
		return 0;
	}
	for(j = i; j < list->length; j++){
		list->data[j] = list->data[j + 1];
	}
	list->length--;
	return 1;
}//删除表中i位置的元素

void PrintList(SqList *list){
	int i;
	for(i = 0; i < list->length; i++){
		printf("%d-->%d\n", i, list->data[i]);	
	}
	if(i == list->length){
		printf("\n");
	}
}//顺序输出所有元素值

int Empty(SqList *list){
	if(list->length == 0) {
		return 1;
	} else {
		return 0;
	}
}//表判空操作

