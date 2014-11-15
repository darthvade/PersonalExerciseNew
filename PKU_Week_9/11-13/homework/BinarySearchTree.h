#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__

#include <queue>
#include <iostream>

//BST的数据结点模板定义
template <typename T> 
struct BSTreeNode {
	BSTreeNode() : data(0), lchild(nullptr), rchild(nullptr) {}
	BSTreeNode(const T &d) : data(d), lchild(nullptr), rchild(nullptr) {}
	T data;
	BSTreeNode *lchild;
	BSTreeNode *rchild;
};

//BST模板定义
template <typename T>
class BinarySearchTree {
public:
	//默认构造函数
	BinarySearchTree() : _root(nullptr) , _numleaves(0), _sumvalueleaves(0) {}
	//由初始化队列初始化BST
	BinarySearchTree(const std::queue<T> &initq) : _root(nullptr) , _numleaves(0), _sumvalueleaves(0) {
		std::queue<T> innerq(initq);
		createBST(_root, innerq);	
	}
	//析构函数
	~BinarySearchTree() {
		deleteBST(_root);	
	}
	//插入数据新结点
	bool InsertNode(const T &t) {
		insert(_root, t);	
	}
	//得到叶子结点数
	unsigned int getNumLeaves() {
		_numleaves = 0;
		_sumvalueleaves = 0;
		TraverseCountLeaves(_root);	
		return _numleaves;
	}
	//得到叶结点值之和
	int getSumValueLeaves() {
		_numleaves = 0;
		_sumvalueleaves = 0;
		TraverseCountLeaves(_root);
		return _sumvalueleaves;
	}
private:
	//计算叶子结点数及叶结点数据和
	void TraverseCountLeaves(BSTreeNode<T> *&root) {
		if(nullptr != root) {
			if((nullptr == root->lchild) && (nullptr == root->rchild)) {
				_numleaves++;
				_sumvalueleaves += root->data;
			}
			TraverseCountLeaves(root->lchild);
			TraverseCountLeaves(root->rchild);
		} else {
			return;
		}	
	}
	//插入新结点
	bool insert(BSTreeNode<T> *&root, const T &t) {
		if(nullptr == root) {
			root = new BSTreeNode<T>(t);
			return true;
		}	
		if(t == root->data) {
			return false;
		}
		if(t > root->data) {
			return insert(root->rchild, t);
		}
		return insert(root->lchild, t);
	}
	//递归构造BST
	void createBST(BSTreeNode<T> *&root, std::queue<T> &initq) {
		while(!initq.empty()) {
			insert(root, initq.front());
			initq.pop();
		}
	}
	//递归删除BST
	void deleteBST(BSTreeNode<T> *&root) {
		if(root != nullptr) {
			deleteBST(root->lchild);
			deleteBST(root->rchild);	
			delete root;
		} else {
			return;
		}
	}

	BSTreeNode<T> *_root; //根结点指针
	unsigned int _numleaves; //叶子结点的数目
	T _sumvalueleaves; //叶子结点值的合计数
};

#endif
