#ifndef __COMPLETEBINARYTREE_H__
#define __COMPLETEBINARYTREE_H__

#include <vector>
#include <iostream>

/*
 *	注：完全二叉树的结点编号从1开始
 */

template <typename T>
class CompleteBinaryTree {
public:
	//默认构造函数
	CompleteBinaryTree() : _nodearray(nullptr) , _size(0) {}
	//使用初始化数组初始化CBT
	CompleteBinaryTree(const std::vector<T> &initv) : _nodearray(nullptr), _size(0) {
		_nodearray = new T[initv.size() + 1]();	
		_nodearray[0] = initv.size();
		for(std::size_t i = 1; i != initv.size(); ++i) {
			_nodearray[i] = initv[i - 1];
		}
		_size = initv.size();
	}
	//若存在，打印指定结点的父结点和所有孩子结点
	void printParentsChildren(unsigned int index) {
		if(index < 1 || index > _size) {
			std::cout << "ERROR: index out of range!" << std::endl;	
		} 
		printParents(index);
		printChildren(index);
	}
	//析构函数
	~CompleteBinaryTree() {
		delete [] _nodearray;	
	}
private:
	//打印父结点
	void printParents(unsigned int index) {
		unsigned int pindex;
		pindex = index / 2;	
		if(pindex > 0) {
			std::cout << "Parents of [Index " << index << "] is " << _nodearray[pindex] << std::endl;
		} else {
			std::cout << "[Index " << index << "] do NOT have parents." << std::endl;	
		}
	}
	//打印孩子结点
	void printChildren(unsigned int index) {
		unsigned int lchildindex, rchildindex;
		lchildindex = index * 2;
		rchildindex = index * 2 + 1;	
		if(lchildindex <= _size) {
			std::cout << "left child of [index " << index << "] is " << _nodearray[lchildindex] << std::endl;
		} else {
			std::cout << "[Index " << index << "] do NOT have left child" << std::endl;	
		}
		if(rchildindex <= _size) {
			std::cout << "right child of [Index " << index << "] is " << _nodearray[rchildindex] << std::endl;
		} else {
			std::cout << "[Index " << index << "] do NOT have right child" << std::endl;	
		}
	}
	T *_nodearray;	
	unsigned int _size;
};

#endif
