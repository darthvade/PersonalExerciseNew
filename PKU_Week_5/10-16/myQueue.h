/*
 * myQueue（泛型版）
 *
 */

#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

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

//链式队列模板定义
template <typename T>
class myQueue {
public:
	myQueue() : _nsize(0) {
		_phead = new struct Node<T>(T(), NULL);
		_pfront = _phead->next;
		_pback = _phead->next;
	}
	~myQueue() {
		removeAll();
		delete _phead;	
	}
	int size() {
		return _nsize;
	}
	bool empty() {
		return _nsize > 0 ? false : true;
	}
	T front() {
		return _pfront->data;
	}
	T back() {
		return _pback->data;
	}
	void push(T input) {
		auto insert = new struct Node<T>(input, NULL);
		if(_pback == NULL) {
			_pback = insert;	
			_pfront = insert;
			_phead->next = insert;
		} else {
			_pback->next = insert;
			_pback = _pback->next;	
		}
		++_nsize;		
	}
	void pop() {
		if(_nsize == 0) {
			return;
		}
		auto pdel = _pfront;
		_pfront = _pfront->next;
		_phead->next = _pfront;
		delete pdel;
		--_nsize;
	}
private:
	void removeAll() {
		auto p = _pfront;	
		while(p) {
			auto temp = p;
			p = p->next;
			delete temp;	
		}
	}
	struct Node<T> *_phead; //链式队列头指针
	struct Node<T> *_pfront; //队列数据头指针
	struct Node<T> *_pback;  //队列数据尾指针
	int _nsize; //队列内结点数量（即，队列内数据量）
};

#endif
