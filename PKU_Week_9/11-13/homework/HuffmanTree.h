#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include "./PriorityQueue.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

template <typename T>
struct myless {
	bool operator() (const T &a, const T &b) {
		return a < b ? true : false;	
	}
};

//哈夫曼树数据结点
struct HTreeNode {
	HTreeNode() : key(0), huffcode(), lchild(nullptr), rchild(nullptr) {}
	HTreeNode(const Keytype &k) : key(k), huffcode(), lchild(nullptr), rchild(nullptr) {}
	Keytype key; //权值
	std::string huffcode; //权值对应的哈夫曼编码
	HTreeNode *lchild; //左孩子指针
	HTreeNode *rchild; //右孩子指针
};

class HuffmanTree {
public:
	//默认构造函数
	HuffmanTree() : _root(nullptr) {}
	//由权值向量初始化哈夫曼树
	HuffmanTree(const std::vector<int> initv) : _root(nullptr) {
		PriorityQueue<HTreeNode*, myless<int>> pq;
		for(auto i : initv) {
			auto pinsert = new HTreeNode(i);	
			pq.insert(pinsert, i);
		}	
		do {
			auto pnewnode = new HTreeNode();
			pnewnode->lchild = pq.top().data;		
			pnewnode->key += pq.top().key;
			pq.pop();
			pnewnode->rchild = pq.top().data;
			pnewnode->key += pq.top().key;
			pq.pop();
			pq.insert(pnewnode, pnewnode->key);
		} while(!pq.empty() && pq.size() > 1);
		_root = pq.top().data;
	}
	//取得哈夫曼编码
	void getHuffmanCode() {
		computeCode(_root);	
	}	
	//取得相应权值的哈夫曼编码
	std::string operator[] (int key) {
		return _codemap[key];	
	}
	//析构函数
	~HuffmanTree() {
		deleteTree(_root);			
	}
private:
	//计算哈夫曼编码
	void computeCode(HTreeNode *&root) {
		if(root != nullptr) {
			if(root->lchild != nullptr) {
				root->lchild->huffcode += root->huffcode;
				root->lchild->huffcode.push_back('0');
				//std::cout << "DEBUG 0" << std::endl; //DEBUG
			}
			//std::cout << root->key << std::endl; //DEBUG
			if(root->rchild != nullptr) {
				root->rchild->huffcode += root->huffcode;
				root->rchild->huffcode.push_back('1');
				//std::cout << "DEBUG 1" << std::endl; //DEBUG
			}
			if((root->lchild == nullptr) && (root->rchild == nullptr)) {
				_codemap[root->key] = root->huffcode;
				//std::cout << "DEBUG map" << std::endl; //DEBUG
			}
			computeCode(root->lchild);
			computeCode(root->rchild);	
		} else {
			return;
		}	
	}
	//删除编码树
	void deleteTree(HTreeNode *&root) {
		if(root) {
			deleteTree(root->lchild);	
			deleteTree(root->rchild);	
			delete root;
		} else {
			return;
		}	
	}

	HTreeNode *_root; //编码树树根
	std::unordered_map<Keytype, std::string> _codemap; //权值-编码映射
};

#endif
