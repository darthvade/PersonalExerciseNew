#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode, *Tree;

int insert_tree(Tree *t, int key); //插入一个元素

int destory_tree(Tree *t); //销毁二插树（后续遍历）
int deep_tree(Tree t); //求深度 （左右子树较大者加一）
Tree mirror_tree(Tree t); //求镜像
Tree copy_tree(Tree t); //复制二插树

void pre_order(Tree t) {
	if(t) {
		printf("%d ", t->data);
		pre_order(t->left);
		pre_order(t->right);
	} else {
		return;
	}
}

void mid_order(Tree t) {
	if(t) {
		mid_order(t->left);
		printf("%d ", t->data);
		mid_order(t->right);
	} else {
		return;
	}
}

void aft_order(Tree t) {
	if(t) {
		aft_order(t->left);
		aft_order(t->right);
		printf("%d ", t->data);
	} else {
		return;
	}
}

int main() {
	Tree t = NULL;
	insert_tree(&t, 8);
	insert_tree(&t, 5);
	insert_tree(&t, 13);
	insert_tree(&t, 4);
	insert_tree(&t, 4);
	insert_tree(&t, 6);
	insert_tree(&t, 6);
	pre_order(t);
	putchar('\n');
	return 0;
}

int insert_tree(Tree *t, int key) {
	if(*t == NULL) {
		(*t) = (TreeNode *)malloc(sizeof(TreeNode));
		(*t)->data = key;
		return 1;
	} else if((*t)->data == key) {
		return 1;
	} else if ((*t)->data > key) {
		return insert_tree(&(*t)->left, key);
	} else if ((*t)->data < key) {
		return insert_tree(&(*t)->right, key);
	}
	return 0;
}  //插入一个元素

int destory_tree(Tree *t) {

} //销毁二插树（后续遍历）

int deep_tree(Tree t) {

} //求深度 （左右子树较大者加一）

Tree mirror_tree(Tree t) {

} //求镜像

Tree copy_tree(Tree t) {

}  //复制二插树





