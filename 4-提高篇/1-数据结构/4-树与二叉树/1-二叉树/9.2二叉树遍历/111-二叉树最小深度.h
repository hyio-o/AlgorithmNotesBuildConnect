//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

#include "../A-二叉树定义.h"

int minDepth(BiTNode *root) {
    if (!root) return 0;
    int leftDepth = minDepth(root->lchild);
    int rightDepth = minDepth(root->rchild);

    if (root->lchild == NULL && root->rchild != NULL) {
        return 1 + rightDepth;
    }
    if (root->lchild != NULL && root->rchild == NULL) {
        return 1 + leftDepth;
    }
    int result = 1 + min(leftDepth, rightDepth);
    return result;
}

int minDepth_N(BiTNode *root) {
    if (!root) return 0;
    if (root->lchild == NULL && root->rchild != NULL) {
        return 1 + minDepth_N(root->rchild);
    }
    if (root->lchild != NULL && root->rchild == NULL) {
        return 1 + minDepth_N(root->lchild);
    }
    return 1 + min(minDepth_N(root->lchild), minDepth_N(root->rchild));

}


// Level Order
//只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点


//
// Created by 陈至宇 on 2022/7/17.
//

#ifndef ALGORITHMNOTESBUILDING_111_二叉树最小深度_H
#define ALGORITHMNOTESBUILDING_111_二叉树最小深度_H

#endif //ALGORITHMNOTESBUILDING_111_二叉树最小深度_H
