/*
 *	二叉树（指针实现）
 */

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <queue>
#include <string>
#include <stack>
#include <iostream>

/*
 * 二叉树数据结点模板定义
 */
template <typename T>
struct BinaryTreeNode {
	BinaryTreeNode() :data(0), lchild(nullptr), rchild(nullptr) {};
	BinaryTreeNode(T d) : data(d), lchild(nullptr), rchild(nullptr) {}
	T data; //存储数据
	BinaryTreeNode *lchild; //左孩子指针
	BinaryTreeNode *rchild; //右孩子指针
};

/*
 * 二叉树模板类定义
 */
template <typename T>
class BinaryTree {
public:
	//默认构造函数
	BinaryTree() : _root(nullptr) {}
	//从输入队列初始化二叉树
	BinaryTree(const std::queue<T> &initv,const T &nochildmask) {
		std::queue<T> innerv(initv);
		CreatTree(_root, innerv, nochildmask);
	}
	//先根遍历二叉树[打印数据到标准输出]
	void printPreorderTrverse() {
		Preorder(_root);	
	}
	//析构函数
	~BinaryTree() {
		deleteTree(_root);	
	}
	//打印中序表达式（未去除冗余括号）
	void printInorderExp() {
		InorderExp(_root);	
	}
	//查找结点双亲（层序查找）
	T getParentsValue(const T &t) {
		std::queue<BinaryTreeNode<T>*> searchq;		
		searchq.push(_root);
		while(!searchq.empty()) {
			auto nodep = searchq.front();
			if(nodep->lchild && nodep->lchild->data == t) {
				return nodep->data;
			}
			if(nodep->rchild && nodep->rchild->data == t) {
				return nodep->data;
			}
			if(nodep->lchild){
				searchq.push(nodep->lchild);
			}
			if(nodep->rchild){
				searchq.push(nodep->rchild);
			} 
			searchq.pop();
		}
		return 0;
	}
private:
	/*--内部方法-begin--*/
	//打印中序表达式（未去除冗余括号）
	void InorderExp(BinaryTreeNode<T> *&root) {
		std::queue<T> postfixq;	//后缀表达式队列
		getPostfix(root, postfixq); //生成后缀表达式
		std::stack<std::string> resultstack;
		T preoperator = 0;
		while(!postfixq.empty()) {
			T temp = postfixq.front();	
			if((temp != '/') && (temp != '*') && (temp != '+') && (temp != '-')) {
				std::string is;
				is.push_back(temp);
				resultstack.push(is);	
				postfixq.pop();
			} else {
				std::string right = resultstack.top();
				resultstack.pop();
				std::string left = resultstack.top();	
				resultstack.pop();
				//取得当前操作符
				std::string is;
				is.push_back(postfixq.front());
				std::string insert = "(" + left + is + right + ")";
				//std::string insert = left + is + right;
				resultstack.push(insert);
				preoperator = postfixq.front();
				postfixq.pop();
			}
		}
		std::cout << resultstack.top() << std::endl;
	}
	//取得后缀表达式
	void getPostfix(BinaryTreeNode<T> *&root, std::queue<T> &inputq) {
		if(root != nullptr) {
			getPostfix(root->lchild, inputq);
			getPostfix(root->rchild, inputq);
			inputq.push(root->data);	
		} else {
			return;
		}	
	}
	//判断是否是最下层操作符
	bool isLowestOper(BinaryTreeNode<T> *&root) {
		if(	root->lchild->data != '+' && 
			root->lchild->data != '-' &&
		 	root->lchild->data != '*' &&
		 	root->lchild->data != '/' &&
			root->rchild->data != '+' && 
			root->rchild->data != '-' &&
		 	root->rchild->data != '*' &&
		 	root->rchild->data != '/' ) {
			return true;	
		} else {
			return false;
		}
	}
	//取得子树运算符
	char getLowerOper(BinaryTreeNode<T> *&root) {
		if(	root->lchild->data == '+' ||
			root->lchild->data == '-' ||
		 	root->lchild->data == '*' ||
		 	root->lchild->data == '/') {
			return root->lchild->data;	
		} 
		if(	root->rchild->data == '+' ||
			root->rchild->data == '-' ||
		 	root->rchild->data == '*' ||
		 	root->rchild->data == '/') {
			return root->rchild->data;	
		}
		return 0;
	}
	//取得运算符优先级
	unsigned int getOperPriority(char oper) {
		if(oper == '*' || oper == '/') {
			return 2;
		} else {
			return 1;
		}
	}
	//先根遍历打印
	void Preorder(BinaryTreeNode<T> *&root) {
		if(root != nullptr) {
			printNodeData(root);
			Preorder(root->lchild);
			Preorder(root->rchild);
		}
		else {
			return;
		}
	}
	//删除二叉树
	void deleteTree(BinaryTreeNode<T> *&root) {
		if(root != nullptr) {
			deleteTree(root->lchild);
			deleteTree(root->rchild);
			delete root;
		}
		else {
			return;
		}
	}
	//打印结点到标准输出
	void printNodeData(BinaryTreeNode<T> *&root) {
		//std::cout << root->data << std::endl;	
		std::cout << root->data << " ";	
	}
	/*
	 * 层序建立二叉树
	 */
	void CreatTree(BinaryTreeNode<T> *&root, std::queue<T> &initv,const T &nochildmask) {
		std::queue<BinaryTreeNode<T>*> nochildq;
		if(!initv.empty() && (nochildmask != initv.front())) {
			root = new BinaryTreeNode<T>(initv.front());
			nochildq.push(root);
			initv.pop();
		} else {
			return;
		}
		while(!nochildq.empty() && !initv.empty()) {
			BinaryTreeNode<T> *insert = nochildq.front();	
			nochildq.pop();
			if(initv.front() != nochildmask) {
				insert->lchild = new BinaryTreeNode<T>(initv.front());
				nochildq.push(insert->lchild);
				initv.pop();
			} else {
				initv.pop();
			}
			if(initv.front() != nochildmask) {
				insert->rchild = new BinaryTreeNode<T>(initv.front());
				nochildq.push(insert->rchild);
				initv.pop();
			} else {
				initv.pop();
			}
		}
	}
	/*--内部方法-end--*/

	/*--内部数据-begin--*/
	BinaryTreeNode<T> *_root; //根结点指针
	/*--内部数据-end--*/
};

#endif
