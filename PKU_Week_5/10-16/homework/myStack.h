/*
 * myStack（泛型版）
 *
 */

#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>

#ifndef _NODE_
#define _NODE_
//数据结点模板定义
template <typename T>
struct Node {
	//默认构造函数
	Node() = default;
	//构造函数
	Node(T d, struct Node *p) : data(d), next(p) {}
	//结点数据
	T data;
	//指向下一结点的指针
	struct Node *next;
};
#endif

//链式栈模板定义
template <typename T>
class myStack {
public:
	//构造函数
	myStack() : _nsize(0) {
		_phead = new struct Node<T>(T(), NULL);	
		_ptop = _phead->next;
	}
	//向栈中压入一个元素
	void push(T input) {
		auto insert = new struct Node<T>(input, NULL);
		_ptop = insert;
		insert->next = _phead->next;
		_phead->next = insert;
		++_nsize;
	}
	//从栈中删除一个元素
	void pop() {
		if(_nsize == 0) {
			return;
		}		
		--_nsize;
		auto pdel = _ptop;
		_phead->next = _ptop->next;
		_ptop = _ptop->next;
		delete pdel;
	}
	//判断栈是否为空
	bool empty() const {
		return (_nsize == 0 ? true: false);	
	}
	//返回栈的大小
	int size() {
		return _nsize;
	}
	//返回栈顶元素
	T top() {
		return _ptop->data;
	}
	//析构函数
	~myStack() {
		removeAll();
		delete _phead;	
	}
private:
	//移除栈内的所有元素
	void removeAll() {
		auto p = _ptop;
		while(p) {
			auto temp = p;
			p = p->next;
			delete temp;		
		}	
	}
	struct Node<T> *_phead; //链式栈头指针
	struct Node<T> *_ptop; //栈顶指针
	int _nsize; //栈内结点数量（即，栈内数据量）
};

#endif
