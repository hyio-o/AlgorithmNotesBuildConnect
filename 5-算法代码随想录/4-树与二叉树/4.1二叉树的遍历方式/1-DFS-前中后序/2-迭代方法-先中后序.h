#include "../../../0-初始化定义/4-二叉树定义.h"
#include <vector>


// 统一方法
typedef struct BinNode{
	struct BinNode *Left;
	struct BinNode *Right;
	int Data;
}*BinTree;
typedef struct{
	struct BinNode dataL[MMAXN];
	int len;
}Stack;
class OldSchoolSolution{
public:

	vector<int> preO(TreeNode *root){   // cur工作指针 赋值为 left right
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode *cur=root;
		while(cur || !st.empty())
		{
			while(cur){
				st.push(cur);   // root
				result.push_back(cur->val); // visit
				cur = cur->left;    // left
			}
			if(!st.empty()){
				cur = st.top();
				st.pop();
				cur = cur->right;   // right
			}
		}
		return result;
	}
	vector<int> inO(TreeNode* root){
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode *cur=root;
		while(cur || !st.empty())
		{
			while(cur){
				st.push(cur);   // root
				cur = cur->left;    // left
			}
			if(!st.empty()){
				cur = st.top();
				st.pop();
				result.push_back(cur->val); // visit
				cur = cur->right;   // right
			}
		}
		return result;
	}
	vector<int> postO(TreeNode* root){
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode *cur;
		st.push(root);
		while(!st.empty())
		{
			cur = st.top(); st.pop();

		}
	}
private:
	void visit(TreeNode *cur);
	void PostOrderTraversal(BinTree BT)
	{
		BinTree T = BT;
		Stack S = CreateStack(); // 创建并初始化堆栈 S
		vector<BinTree> v;       // 创建存储树结点的动态数组
		Push(S, T);
		while (!IsEmpty(S))
		{ // 当树不为空或堆栈不空
			T = Pop(S);
			v.push_back(T); // 出栈元素进数组
			if (T->Left)
				Push(S, T->Left);
			if (T->Right)
				Push(S, T->Right);
		}
		reverse(v.begin(), v.end());       // 逆转
		for (int i = 0; i < v.size(); i++) // 输出数组元素
			printf("%d", v[i]->Data);
	}
private:
	BinNode CreateStack();
	bool Push(Stack S, BinTree T);
	BinTree Pop(Stack S);
	bool IsEmpty(Stack S);
};



// 先序遍历：根左右， 但是栈的原因，需要先放入右孩子。

class Solution {    // stack _method
public:
	// 1. push(root) 2. while(!st.empty()) push右 push左
	// 先序遍历 stack
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> result;
		if (root == NULL)
			return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode *node = st.top(); // 中
			st.pop();
			result.push_back(node->val);
			if (node->right)        st.push(node->right); // 右（空节点不入栈）
			if (node->left)        st.push(node->left); // 左（空节点不入栈）
		}
		return result;
	}
	// 后序遍历 stack
	vector<int> postorderTraversal(TreeNode *root) {  // 使用先序遍历方法但逆置
		stack<TreeNode *> st;
		vector<int> result;
		if (root == NULL)
			return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode *node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left)        st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
			if (node->right)        st.push(node->right); // 空节点不入栈
		}
		reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
		return result;
	}
	// 中序遍历 非空 工作指针 或 栈st， 先入左，若无左 访问 中， 再入右； 此时有个问题是回环 tag？
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> st;
		TreeNode *cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { // 指针来访问节点，访问到最底层
				st.push(cur);    // 将访问的节点放进栈
				cur = cur->left; // 左
			} else {
				cur =st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
				st.pop();
				result.push_back(cur->val); // 中
				cur = cur->right;           // 右
			}
		}
		return result;
	}
};



vector<int> preorderTraversal(TreeNode *root) { // stack _method
	TreeNode *cur = root;
	stack<TreeNode *> stack_list;
	vector<int> result;
	while (cur || !stack_list.empty()) {
		if (cur) {
			result.push_back(cur->val);
			stack_list.push(cur);
			cur = cur->left;
		} else {
			cur = stack_list.top();
			stack_list.pop();
			cur = cur->right;
		}
	}
	return result;
}


// preOrder
void preOrder_H(BiTNode *T) {
	SqStack Sq;
	initStack(Sq);
	BiTNode *p = T;
	while (p || !isEmptySq(Sq)) {
		if (p) {
			visit(p);
			Push(Sq, p);
			p = p->lchild;
		} else {
			Pop(Sq, p);
			p = p->rchild;
		}
	}
}

// inOrder
void inOrder_H(BiTNode *T) {
	SqStack Sq;
	initStack(Sq);
	BiTNode *p = T;
	while (p || !isEmptySq(Sq)) {
		if (p) {
			Push(Sq, p);
			p = p->lchild;
		} else {
			Pop(Sq, p);
			visit(p);
			p = p->rchild;
		}
	}
}

class Solution_l {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> st;
		TreeNode *cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { // 指针来访问节点，访问到最底层
				st.push(cur);    // 将访问的节点放进栈
				cur = cur->left; // 左
			} else {
				cur =st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
				st.pop();
				result.push_back(cur->val); // 中
				cur = cur->right;           // 右
			}
		}
		return result;
	}

	// post
	void postOrder_H(BiTNode *T) {
		BiTNode *p = T, *rct = nullptr;
		SqStack Sq;
		initStack(Sq);
		while (p || !isEmptySq(Sq)) {
			if (p) {
				Push(Sq, p);
				p = p->lchild;
			} else {
				Pop(Sq, p);
				if (p->rchild && p->rchild != rct) {
					Push(Sq, p);
					p = p->rchild;
				} else { // 访问结点的条件在于左右孩子都空，
					visit(p);
					rct = p;
					p = nullptr;
				}
			}
		}
	}
};





//
// Created by 陈至宇 on 2024/1/20.
//

#ifndef ALGORITHMNOTESBUILDING_2_迭代方法_先中后序_H
#define ALGORITHMNOTESBUILDING_2_迭代方法_先中后序_H

#endif //ALGORITHMNOTESBUILDING_2_迭代方法_先中后序_H
