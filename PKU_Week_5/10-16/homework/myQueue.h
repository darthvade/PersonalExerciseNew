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
	//默认构造函数
	Node() = default;
	//构造函数
	Node(T d, struct Node *p) : data(d), next(p) {}
	//结点数据
	T data;
	//指向下一个结点的指针
	struct Node *next;
};
#endif

//链式队列模板定义
template <typename T>
class myQueue {
public:
	//构造函数
	myQueue() : _nsize(0) {
		_phead = new struct Node<T>(T(), NULL);
		_pfront = _phead->next;
		_pback = _phead->next;
	}
	//析构函数
	~myQueue() {
		removeAll();
		delete _phead;	
	}
	//返回队列大小
	int size() {
		return _nsize;
	}
	//判断队列是否为空
	bool empty() {
		return _nsize > 0 ? false : true;
	}
	//返回队头元素
	T front() {
		return _pfront->data;
	}
	//返回队尾元素
	T back() {
		return _pback->data;
	}
	//向队尾插入一个新元素
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
	//从队头删除一个元素
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
	//移除队列内的所有元素
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
