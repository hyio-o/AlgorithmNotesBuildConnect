#include "../A-二叉树定义.h"

// define: 如果左节点不为空，&&且左节点没有左右孩子，那么这个节点的左节点就是左叶子
// 左结点∃ && 左结点为叶子结点 ==> 左叶子
bool isLeftNode(BiTNode *root) {
    if (root->lchild != NULL && root->lchild->lchild == NULL && root->lchild->rchild == NULL) {
        // procedures
    }
}

class Solution {
public:
    int sumOfLeftLeaves(BiTNode *root) {
        // 后序遍历
        if (root == NULL) return 0;
        int leftVal = sumOfLeftLeaves(root->lchild);
        int rightVal = sumOfLeftLeaves(root->rchild);

        int midVal = 0;
        // 得到左叶子
        if (root->lchild != NULL && root->lchild->lchild == NULL && root->lchild->rchild == NULL) {
            // procedures
            midVal = root->lchild->data;
        }
        int sum = midVal + leftVal + rightVal;
        return sum;
    }
};
//
// Created by 陈至宇 on 2022/7/31.
//

#ifndef ALGORITHMNOTESBUILDING_404_左叶子之和_H
#define ALGORITHMNOTESBUILDING_404_左叶子之和_H

#endif //ALGORITHMNOTESBUILDING_404_左叶子之和_H
