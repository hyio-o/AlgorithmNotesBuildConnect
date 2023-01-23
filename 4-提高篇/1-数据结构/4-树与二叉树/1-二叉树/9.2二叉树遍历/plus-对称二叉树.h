#include "../A-二叉树定义.h"

// 法一 ： 递归
class Solution {
public:
    bool compare(BiTNode *left, BiTNode *right) {
        if (left == NULL && right == NULL) return true;
        else if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left->data != right->data) return false;
        //else    return true;
        bool outside = compare(left->lchild, right->rchild); // 返回左的左，右的右
        bool inside = compare(left->rchild, right->lchild);  // 返回左的右，右的左
        bool isSame = outside && inside;
        return isSame;
        //else return compare(left->lchild, right->rchild) && compare(left->rchild, right->lchild);
    }

    bool isSymmetric(BiTNode *root) {
        if (root == NULL) return true;
        return compare(root->lchild, root->rchild);
    }
};

// 法二 ： 迭代
bool isSymmetric(BiTree root) {
    if (root == NULL) return true;
    // 左右子树入队列
    SeQueue Se;
    BiTNode *leftNode, *rightNode;
    enQueue(Se, root->lchild);
    enQueue(Se, root->rchild);
    while (!isEmptySe(Se)) { // 判断两棵树是否相互对称
        deQueue(Se, leftNode);
        deQueue(Se, rightNode);
        // 左右结点同时为空，继续判断
        if (!leftNode && !rightNode) continue;
        // 左右至少一个不为空，或左右data域不相等
        if ((!leftNode || !rightNode || (leftNode->data != rightNode->data))) return false;
        //入队列 左的左， 右的右； 左的右， 右的左
        enQueue(Se, leftNode->lchild);
        enQueue(Se, rightNode->rchild);
        enQueue(Se, leftNode->rchild);
        enQueue(Se, rightNode->lchild);
    }
    return true;
}


//
// Created by 陈至宇 on 2022/6/19.
//

#ifndef ALGORITHMNOTESBUILDING_PLUS_对称二叉树_H
#define ALGORITHMNOTESBUILDING_PLUS_对称二叉树_H

#endif //ALGORITHMNOTESBUILDING_PLUS_对称二叉树_H
