#ifndef __PROGRAMTASKS_H__
#define __PROGRAMTASKS_H__

#include "SingleLinkedList.h"

struct ProgramTasks {
	//第一题：合并非递减有序链表为新的不重复非递减有序链表
	//函数说明：参数a为其一链表，参数b为另一链表，合并后的结果存储在a链表中。
	//算法说明：使用两个指针分别指向两个链表的第一个数据结点，
	//			之后比较两个链表中较小的结点，将这个结点按"尾插法"插入a链表的尾结点之后,
	//			两指针按情况后移，不断循环这种过程直到两个指针都指向尾结点之后的位置。
	//算法时间复杂度：O(m+n), m为a链表长度，n为b链表长度
	//算法空间复杂度：O(1)
	template <typename T>
	static void MergeNondescList(SingleLinkedList<T> &a, SingleLinkedList<T> &b) {
		//只要有一个链表为空就返回
		if(!a._length || !b._length) {
			return;
		}
		//生成两个指针分别指向两个链表的第一个数据结点
		auto pa = a._phead->next; 
		auto pb = b._phead->next;
		auto atail = a._phead;	//新链表的尾指针
		a._phead->next = NULL;  //割断新链表与原链表的关系
		//生成新链表的第一个数据结点
		if(pa->data <= pb->data) {
			a._phead->next = pa;
			atail = pa;
			pa = pa->next;
			atail->next = NULL;
		} else {
			a._phead->next = pb;
			atail = pb;
			pb = pb->next;
			atail->next = NULL;
		}
		//归并两个链表余下的结点
		//注：直到任意一个为空为止
		while(pa && pb) {
			if(pa->data <= pb->data) { 
				//选择但前数据值较小的结点
				//如果当前选定结点的数据值与新结点的尾结点
				//的数据值相等，则pa/pb指针后移
				if(pa->data == atail->data) {
					pa = pa->next;
				} else {
					atail->next = pa;
					atail = pa;
					pa = pa->next;
					atail->next = NULL;	
				}
			} else if (pa->data > pb->data) {
				if(pb->data == atail->data) {
					pb = pb->next;
				} else {
					atail->next = pb;
					atail = pb;
					pb = pb->next;
					atail->next = NULL;
				}
			} 	
		}
		//以下两个while循环完成两个链表可能没有归并完成的
		//剩余链表的去重归并
		while(pa) {
			if(pa->data == atail->data) {
				pa = pa->next;
			} else {
				atail->next = pa;
				atail = pa;
				pa = pa->next;
				atail->next = NULL;
			}
		}
		while(pb) {
			if(pb->data == atail->data) {
				pb = pb->next;
			} else {
				atail->next = pb;
				atail = pb;
				pb = pb->next;
				atail->next = NULL;
			}
		}
	}

	//第二题：合并非递减有序链表为新的不重复非递增有序链表
	//函数说明：参数a为其一链表，参数b为另一链表，合并后的结果存储在a链表中。
	//算法说明：使用两个指针分别指向两个链表的第一个数据结点，
	//			之后比较两个链表中较小的结点，将这个结点按"头插法"插入a链表的头结点之后,
	//			两指针按情况后移，不断循环这种过程直到两个指针都指向尾结点之后的位置。
	//算法时间复杂度：O(m+n), m为a链表长度，n为b链表长度
	//算法空间复杂度：O(1)
	template <typename T>
	static void MergeNonincList(SingleLinkedList<T> &a, SingleLinkedList<T> &b) {
		//只要有一个链表为空就返回
		if(!a._length || !b._length) {
			return;
		}
		//生成两个指针分别指向两个链表的第一个数据结点
		auto pa = a._phead->next; 
		auto pb = b._phead->next;
		//auto atail = a._phead;	//新链表的尾指针
		a._phead->next = NULL;  //割断新链表与原链表的关系
		//生成新链表的第一个数据结点
		if(pa->data <= pb->data) {
			auto temp = pa;
			pa = pa->next;
			temp->next = NULL;
			a._phead->next = temp;
		} else {
			auto temp = pb;
			pb = pb->next;
			temp->next = NULL;
			a._phead->next = temp;
		}
		//归并两个链表余下的结点
		//注：直到任意一个为空为止
		while(pa && pb) {
			if(pa->data <= pb->data) { 
				//选择但前数据值较小的结点
				//如果当前选定结点的数据值与新结点的尾结点
				//的数据值相等，则pa/pb指针后移
				if(pa->data == a._phead->next->data) {
					pa = pa->next;
				} else {
					auto temp = pa;
					pa = pa->next;
					temp->next = a._phead->next;
					a._phead->next = temp;
				}
			} else if (pa->data > pb->data) {
				if(pb->data == a._phead->next->data) {
					pb = pb->next;
				} else {
					auto temp = pb;
					pb = pb->next;
					temp->next = a._phead->next;
					a._phead->next = temp;
				}
			}
		}
		//以下两个while循环完成两个链表可能没有归并完成的
		//剩余链表的去重归并
		while(pa) {
			if(pa->data == a._phead->next->data) {
				pa = pa->next;
			} else {
				auto temp = pa;
				pa = pa->next;
				temp->next = a._phead->next;
				a._phead->next = temp;	
			}
		}
		while(pb) {
			if(pb->data == a._phead->next->data) {
				pb = pb->next;
			} else {
				auto temp = pb;
				pb = pb->next;
				temp->next = a._phead->next;
				a._phead->next = temp;
			}
		}
	}

	//第三题：寻找单链表中含有最大值的结点位置
	//函数说明：参数a为要查找的链表，返回值为结点在链表中的位置
	//		 	注：第一个数据结点位置为1, 之后递增
	//		 	    若空链表，返回0
	//算法说明：从第一个数据结点开始顺序查找并比较，直到遍历完所有结点，输出结果
	//算法时间复杂度：O(m), m为a链表长度
	//算法空间复杂度：O(1)
	template <typename T>	
	static int findMax(SingleLinkedList<T> &a) {
		if(a._length == 0) {
			return 0;
		} 	
		int pos = 1;
		int maxpos = 1;
		T maxValue = a._phead->next->data;
		auto p = a._phead->next;
		while(p) {
			if(p->data > maxValue) {
				maxValue = p->data;
				maxpos = pos;
			}	
			p = p->next;
			++pos;
		}	
		return maxpos;
	}

	//第四题：逆置链表
	//函数说明：参数a为要逆置的链表
	//算法说明：若链表长度大于1，则从第二个数据结点开始
	//			使用“头插法”将从第二个数据结点开始的所有
	//			结点插入到头结点之后，生成的新链表即为
	//			原链表的逆置链表
	//算法时间复杂度：O(m), m为a链表长度
	//算法空间复杂度：O(1)
	template <typename T>
	static void reverseList(SingleLinkedList<T> &a) {
		if(a._length == 0 || a._length == 1) {
			return;
		}	
		auto p = a._phead->next->next;
		a._phead->next->next = NULL;
		while(p) {
			auto temp = p;
			p = p->next;
			temp->next = a._phead->next;
			a._phead->next = temp;
		}
	}

	//第五题：删除指定范围内的链表结点
	//函数说明：参数a为要部分删除的链表, left为左边界, right为右边界
	//算法说明：顺序查找需要删除的区间边界的数据结点，
	//			链接删除范围之外的两端链表，并delete需要删除的链表片段
	//算法时间复杂度：O(m), m为a链表长度
	//算法空间复杂度：O(1)
	template <typename T>
	static void removeRange(SingleLinkedList<T> &a, T left, T right) {
		if(a._length == 0 || left > right) {
			return;
		}	
		//寻找左区间的前一个结点
		auto preleft = a._phead;
		while(preleft->next->data < left) {
			preleft = preleft->next;	
		}
		//寻找右区间结点
		auto nextright = preleft;
		auto preright = preleft; //保存右区间结点的前一个结点，便于删除区间结点
		while(nextright->data <= right) {
			preright = nextright;
			nextright = nextright->next;	
		}
		//记录删除的链表的第一个结点指针
		auto pdelete = preleft->next;
		//链接不需删除的链表
		preleft->next = nextright;
		//删除给定范围内的数据结点	
		preright->next = NULL;
		while(pdelete) {
			auto temp = pdelete;
			pdelete = pdelete->next;
			delete temp;
		}
	}
	
};

#endif
