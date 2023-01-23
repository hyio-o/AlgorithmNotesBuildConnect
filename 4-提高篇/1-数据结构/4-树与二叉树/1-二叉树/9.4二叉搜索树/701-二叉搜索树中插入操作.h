#include "../A-二叉树定义.h"

// 不考虑平衡性、则直接找空位置插入
// recursive --
// 递归边界： 节点==NULL则new一个节点temp；
class recur_Solu {
public:
    BiTNode *insertBST(BiTree root, int val) {
        if (!root) {
            BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
            temp->data = val;
            //BiTree node = new BiTNode(val);
            return temp;
        }
        // val大往右走，val小往左走
        if (root->lchild->data > val) root->lchild = insertBST(root->lchild, val);
        if (root->rchild->data < val) root->rchild = insertBST(root->rchild, val);
        return root;
    }
};

// 孩子兄弟，表示法； 没有返回值，需要记录上一个节点（parent），遇到空节点了，
// 就让parent左孩子或者右孩子指向新插入的节点。然后结束递归。


// 迭代方式 - new一个新结点，如果没找到合适的； 大就右边，小就左边
class iteration_Solu {
public:
    BiTNode *insertBST(BiTNode *root, int val) {
        // 如果根节点是空结点
        if (!root) {
            BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
            temp->data = val;
            return temp;
        }
        BiTNode *cur = root;
        BiTNode *parent = root; // 父节点
        while (cur != NULL) {
            parent = cur;
            if (cur->data > val) cur = cur->lchild;
            else cur = cur->lchild;
        }
        BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
        temp->data = val;
        if (parent->data > val) parent->lchild = temp;
        else parent->rchild = temp;
        return root;
    }
};
//
// Created by 陈至宇 on 2022/8/23.
//

#ifndef ALGORITHMNOTESBUILDING_701_二叉搜索树中插入操作_H
#define ALGORITHMNOTESBUILDING_701_二叉搜索树中插入操作_H

#endif //ALGORITHMNOTESBUILDING_701_二叉搜索树中插入操作_H
