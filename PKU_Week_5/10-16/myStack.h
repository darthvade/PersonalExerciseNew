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
	Node() = default;
	Node(T d, struct Node *p) : data(d), next(p) {}
	T data;
	struct Node *next;
};
#endif

//链式栈模板定义
template <typename T>
class myStack {
public:
	myStack() : _nsize(0) {
		_phead = new struct Node<T>(T(), NULL);	
		_ptop = _phead->next;
	}
	void push(T input) {
		auto insert = new struct Node<T>(input, NULL);
		_ptop = insert;
		insert->next = _phead->next;
		_phead->next = insert;
		++_nsize;
	}
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
	bool empty() const {
		return (_nsize == 0 ? true: false);	
	}
	int size() {
		return _nsize;
	}
	T top() {
		return _ptop->data;
	}
	~myStack() {
		removeAll();
		delete _phead;	
	}
private:
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
