/* 声明：本代码完全由本人编写，如假包换：）
 * 
 *
 * 单链表（泛型版）
 * 注：打印链表操作需要结点数据类型支持“<<”操作符
 */

#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include <vector>
#include <iostream>

//定义链表结点
template <typename T>
struct Node {
	//默认构造函数
	Node() = default;
	//构造函数
	Node(T idata, struct Node *inext) : 
		data(idata), next(inext) {}
	T data; //结点数据
	struct Node *next; //指向下一结点的指针	
};

//定义单链表模板类
template <typename T>
class SingleLinkedList {
friend struct ProgramTasks;
public:
	//链表类默认构造函数
	//注：生成只含头结点的空链表,链表长度为零
	SingleLinkedList() : _length(0) {
		_phead = new struct Node<T>(T(), NULL);	//生成头结点
	}
	//链表类构造函数
	//注：使用指定类型的vector，以头插法初始化链表
	SingleLinkedList(const std::vector<T> &input) {
		_phead = new struct Node<T>(T(), NULL); //生成头结点
		//使用反向迭代器遍历输入的vector,同时使用头插法初始化链表
		for(auto p = input.rbegin(); p != input.rend(); ++p) {
			auto temp = new struct Node<T>(*p, _phead->next);	
			_phead->next = temp;
			++_length;
		}
	}
	//链表类析构函数
	~SingleLinkedList() {
		auto p = _phead->next;
		while(p) {
			auto temp = p;
			p = p->next;
			delete temp;	
		}
		delete _phead;
	}
	//打印链表内所有元素
	//注：以头结点为起始结点
	void printAll() {
		auto p = _phead->next;
		while(p) {
			std::cout << p->data;
			if(p->next) {
				std::cout << " | ";
			}
			p = p->next;	
		}	
		std::cout << std::endl;
	}
private:
	int _length; //链表长度
	struct Node<T> *_phead; //链表头指针
};

#endif
