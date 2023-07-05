#include "A-二叉树定义.h"
//#include "/Users/chenzhiyu/CLionProjects/
// AlgorithmNotesBuilding/4-提高篇/1-数据结构/1-栈/栈定义.h"


void postOrder_N(BiTNode *T) {
    if (T != NULL) {
        postOrder_N(T->lchild);
        postOrder_N(T->rchild);
        // visit node
        visit(T);
    }
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

vector<Elemtype> preOrder_R(BiTNode *root) {
    stack<BiTNode *> BiTSq;
    vector<Elemtype> result;
    if (!root) return result;
    BiTSq.push(root);
    while (!BiTSq.empty()) {
        BiTNode *temp = BiTSq.top();
        BiTSq.pop();
        result.push_back(temp->data);
        if (temp->lchild) BiTSq.push(temp->lchild);
        if (temp->rchild) BiTSq.push(temp->rchild);
    }
    return result;
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
            } else {  // 访问结点的条件在于左右孩子都空，
                visit(p);
                rct = p;
                p = nullptr;
            }
        }
    }
}



vector<int> postOrder_HH(BiTNode *root)
{
    stack<BiTNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        BiTNode * node = st.top();
        st.pop();
        result.push_back(node->data);
        visit(node);
        if (node->lchild) st.push(node->lchild); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->rchild) st.push(node->rchild); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
}


//
// Created by 陈至宇 on 2022/4/27.
//

