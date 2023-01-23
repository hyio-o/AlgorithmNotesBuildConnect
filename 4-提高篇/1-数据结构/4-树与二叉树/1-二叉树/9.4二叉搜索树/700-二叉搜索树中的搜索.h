#include "../A-二叉树定义.h"
//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。
// 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
//在二叉搜索树中搜索一个节点

// 1 递归法
// 终止条件： 结点为空或者找到该结点 ， return root -(试一试可不可以在函数中复制给index来递归)
// 循环逻辑： 判断该往左还是右走
class recursion_Solu {
public:
    BiTNode *searchBST(BiTNode *root, int val) {
        BiTNode *index = root;
        if (index == NULL || index->data == val) return index;
        // 值比结点小：应该往左边； 反之去右边
        if (index->data > val) return searchBST(index->lchild, val);
        if (index->data < val) return searchBST(index->rchild, val);
        return NULL;
    }
};

// 迭代法
// 思想：一般的二叉树是需要回溯的，当结点走到头就需要走过另一边； 但是二叉搜索树不需要；
class iterlation_Solu {
public:
    BiTNode *searchBST(BiTNode *root, int val) {
        while (!root) {
            if (root->data == val) return root;
            else if (root->data > val) root = root->lchild;
            else root = root->rchild;
        }
        return NULL;
    }
};

//
// Created by 陈至宇 on 2022/8/13.
//

#ifndef ALGORITHMNOTESBUILDING_700_二叉搜索树中的搜索_H
#define ALGORITHMNOTESBUILDING_700_二叉搜索树中的搜索_H

#endif //ALGORITHMNOTESBUILDING_700_二叉搜索树中的搜索_H
