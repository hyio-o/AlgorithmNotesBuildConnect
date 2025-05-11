#include "3_queueDefine.h"

// binary tree class (二叉链表, 三叉链表, 孩子兄弟表示法, 顺序存储)

// 二叉链表, 三叉链表, 孩子兄弟表示法, 顺序存储
// 二叉链表表示法 BinaryLinkedList
class BinaryLinkedList {
public:
	// 0.0 define
	struct ZSBinaryNode {
		elemType data;	// define Nodes data structure, elemType
		struct ZSBinaryNode *lchild, *rchild;
	}*ZSBinaryTree;
	// 1.0 traversing binary tree	,using vector <<STL>>
	// 1.1 recursion traversing
	// 1.1.1 preOrder recurse 根序遍历,先序遍历
	vector<elemType> preOrderRecursion(ZSBinaryNode *root) {
		vector<elemType> my_result;
		preOrderTraversal(root, my_result);
		return my_result;
	}
	// 1.1.2 inOrder recurse 中序遍历
	vector<elemType> inOrderRecursion(ZSBinaryNode *root) {
		vector<elemType> my_result;
		inOrderTraversal(root, my_result);
		return my_result;
	}
	// 1.1.3 postOrder recurse 后序遍历
	vector<elemType> postOrderRecursion(ZSBinaryNode *root) {
		vector<elemType> my_result;
		postOrderTraversal(root, my_result);
		return my_result;
	}
	// 2.0 Revers binary tree
	// 3.0 max depth binary tree
	// 4.0 min depth binary tree


private:
	ZSBinaryNode *myBinaryNode;
	void preOrderTraversal(ZSBinaryNode *cur, vector<elemType> &vec) {
		if (cur == nullptr) {
			return;
		}
		vec.push_back(cur->data);
		preOrderTraversal(cur->lchild, vec);
		preOrderTraversal(cur->rchild, vec);
	}
	void inOrderTraversal(ZSBinaryNode *cur, vector<elemType> &vec) {
		if (cur == nullptr) {
			return;
		}
		inOrderTraversal(cur->lchild, vec);
		vec.push_back(cur->data);
		inOrderTraversal(cur->rchild, vec);
	}
	void postOrderTraversal(ZSBinaryNode *cur, vector<elemType> &vec) {
		if (cur == nullptr) {
			return;
		}
		postOrderTraversal(cur->lchild, vec);
		postOrderTraversal(cur->rchild, vec);
		vec.push_back(cur->data);
	}
};


//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_4_BINARYTREEDEFINE_H
#define ALGORITHMNOTESBUILDING_4_BINARYTREEDEFINE_H

#endif //ALGORITHMNOTESBUILDING_4_BINARYTREEDEFINE_H
