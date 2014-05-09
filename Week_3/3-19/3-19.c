#include "Linklist.h"
#include <stdio.h>
#include <string.h>

typedef struct LinkNode LinkNode;
typedef struct LinkNode* LinkList;

void int_to_string(const int input, char *output); //将整型转换成字符串

char* Mystrstr(const char *src, const char *pattern); //实现strstr (KMP实现)

void del_linkb_from_linka(LinkList La, LinkList Lb); //从a链表中删除b链表中的元素

void split_link(LinkList La, LinkList Lb, LinkList input); //将一个链表拆分成两个链表

void combine_link(LinkList La, LinkList Lb, LinkList Lc); //将一个升序链表和一个降序链表合并

void print_unique_from_link(LinkList L); //不重复地输出升序链表中的元素

int main() {
	/*
	char output[20];
	int_to_string(98765432, output);
	printf("%s\n", output);
	*/
	int arr_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr_b[]	= {9, 8, 3, 2, 1};
	LinkList la;
	LinkList lb;
	LinkList lc;
	init_list(&la);
	init_list(&lb);
	init_list(&lc);
	create_list_tail(la, arr_a, 10);
	create_list_tail(lb, arr_b, 5);
	//debug(lc);
	//debug(lb);
	//del_linkb_from_linka(la, lb);
	//split_link(la, lb, lc);
	combine_link(la, lb, lc);
	debug(lc);
	debug(la);
	debug(lb);
	print_unique_from_link(lc);
	putchar('\n');
	return 0;
}

void int_to_string(const int input, char *output) {
	if(output == NULL) {
		return;
	}
	int i = input;
	int j = 0;
	int stack[20];
	int count = 0;
	do {
		stack[count++] = i % 10;
		i = i / 10;
	}
	while(i);
	while(count) {
		output[j++] = stack[--count] + '0';
	}
	output[j] = '\0';
} //将整型转换成字符串

char* Mystrstr(const char *src, const char *pattern) {
	
}  //实现strstr

void del_linkb_from_linka(LinkList La, LinkList Lb) {
	if(La->next == NULL && Lb->next == NULL) {
		return;
	}
	LinkNode *pa = La->next;
	LinkNode *pb = Lb->next;
	LinkNode *temp;
	LinkNode *pre;
	while(pb) {
		pa = La->next;
		pre = La;
		while(pa) {
			if(pa->data == pb->data) {
				temp = pa;
				pa = pa->next;
				pre->next = pa;
				free(temp);
			} else {
				pre = pa;
				pa = pa->next;
			}
		}
		pb = pb->next;
	}	
}  //从a链表中删除b链表中的元素

void split_link(LinkList La, LinkList Lb, LinkList input) {
	if(input->next == NULL) {
		return;
	}
	int count = 1;
	LinkNode *pos = input->next;
   	while(pos) {
		if((count % 2) == 1) {
			insert_element(La, count, pos->data);			
		} else {
			insert_element(Lb, count, pos->data);
		}
		count++;
		pos = pos->next;
	}
}  //将一个链表拆分成两个链表

void combine_link(LinkList La, LinkList Lb, LinkList Lc) {
	if(La->next == NULL || Lb->next == NULL) {
		return;
	}
	int count = 0;
	reverse(Lb);
	LinkNode *pa = La->next;
	LinkNode *pb = Lb->next;
	while(pa != NULL && pb != NULL) {
		if(pa->data > pb->data) {
			insert_element(Lc, count, pb->data);
			count++;
			pb = pb->next;
		} else {
			insert_element(Lc, count, pa->data);
			count++;
			pa = pa->next;
		}
	}
	while(pa) {
		insert_element(Lc, count, pa->data);
		count++;
		pa = pa->next;
	}
	while(pb) {
		insert_element(Lc, count, pb->data);
		count++;
		pb = pb->next;
	}
}  //将一个升序链表和一个降序链表合并

void print_unique_from_link(LinkList L) {
	if(L->next == NULL) {
		return;
	}
	printf("%d ", L->next->data);
	if(L->next->next == NULL) {
		return;
	}
	LinkNode *p = L->next->next;
	LinkNode *pre = L->next;
	while(p) {
		if(p->data != pre->data) {
			printf("%d ", p->data);
			pre = p;
			p = p->next;
		} else {
			pre = p;
			p = p->next;	
		}
	}
} //不重复地输出升序链表中的元素

		









