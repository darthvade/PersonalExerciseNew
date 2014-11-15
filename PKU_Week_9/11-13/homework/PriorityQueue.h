#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#define _INITSIZE_ 1024
typedef unsigned long long int Keytype;

#include <string.h>

//数据结点模板定义
template <typename T>
struct DataNode {
	DataNode() : data(0), key(0) {}
	DataNode(const T &d, const Keytype &k) : data(d), key(k) {}
	T data; //结点数据
	Keytype key;	//权值
};

//优先级队列模板定义
template <typename T, class F> 
class PriorityQueue {
public:
	//构造函数
	PriorityQueue() : _pqueue(nullptr), _allcsize(0), _size(0), _cmper() {
		_pqueue = new DataNode<T>[_INITSIZE_ + 1]();
		_allcsize = _INITSIZE_ + 1;
	}
	//插入新数据
	void insert(const T &t, Keytype key) {
		DataNode<T> insertnode(t, key);				
		_size++;
		reallocheap(_size);
		_pqueue[_size] = insertnode;
		adjheap();
	}
	//弹出堆顶元素
	void pop() {
		if(_size <= 0) {
			return;
		}	
		swap(_pqueue[1], _pqueue[_size]);
		_size--;
		adjheap();
	}
	//得到栈顶元素
	DataNode<T>& top() {
		return _pqueue[1];	
	}
	//是否为空
	bool empty() {
		return _size == 0 ? true : false;	
	}
	//返回大小
	Keytype size() {
		return _size;
	}
	//析构函数
	~PriorityQueue() {
		delete [] _pqueue;	
	}
private:
	//维护堆性质
	void adjheap() {
		Keytype startpos = _size / 2;
		for(auto index = startpos; index > 0; --index) {
			adjnode(index);	
		}	
	}
	void adjnode(Keytype adjpos) {
		if(adjpos >= _size) {
			return;
		}
		if((adjpos * 2 + 1) <= _size) {
			Keytype changepos = 0;
			if(_cmper(_pqueue[adjpos * 2].key, _pqueue[adjpos * 2 + 1].key)) {
				changepos = adjpos * 2;	
			} else {
				changepos = adjpos * 2 + 1;
			}	
			if(_cmper(_pqueue[changepos].key, _pqueue[adjpos].key)) {
				swap(_pqueue[changepos], _pqueue[adjpos]);
				if(changepos * 2 <= _size) {
					adjnode(changepos);
				}
			}
		} else {
			if(_cmper(_pqueue[adjpos * 2].key, _pqueue[adjpos].key)) {
				swap(_pqueue[adjpos], _pqueue[adjpos * 2]);	
			}	
		}
	}
	//重新分配堆空间
	void reallocheap(Keytype expectsize) {
		if(expectsize > _allcsize - 1) {
			DataNode<T> *newheap = new DataNode<T>[(_allcsize - 1) * 2 + 1]();
			memcpy(newheap, _pqueue, _allcsize * sizeof(DataNode<T>));
			_allcsize = (_allcsize - 1) * 2 + 1;
			delete [] _pqueue;
			_pqueue = newheap;
		} else {
			return;
		}
	}
	//交换数据
	void swap(DataNode<T> &a, DataNode<T> &b) {
		DataNode<T> temp;
		temp = a;
		a = b;
		b = temp;
	}
	DataNode<T> *_pqueue; //栈缓存指针
	Keytype _allcsize; //实际分配栈空间大小
	Keytype _size; //已使用栈空间大小
	F _cmper; //比较器
};

#endif
