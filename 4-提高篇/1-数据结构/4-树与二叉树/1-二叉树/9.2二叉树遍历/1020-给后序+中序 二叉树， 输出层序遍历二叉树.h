// 给后序+中序 二叉树， 输出层序遍历二叉树
/*
 * 二叉树的重建方法：
一、根据前序加中序遍历重建二叉树
构造该二叉树的过程如下：
1. 根据前序序列的第一个元素建立根结点；
2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
3. 在前序序列中确定左右子树的前序序列；
4. 由左子树的前序序列和中序序列建立左子树；
5. 由右子树的前序序列和中序序列建立右子树。

二、根据中序加后序遍历重建二叉树
构造该二叉树的过程如下：
1. 根据后序序列的最后一个元素建立根结点；
2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
3. 在后序序列中确定左右子树的后序序列；
4. 由左子树的后序序列和中序序列建立左子树； // 递归
5. 由右子树的后序序列和中序序列建立右子树。// 递归
*/
// 1。 先重构二叉树
#include "../A-二叉树定义.h"
#include "../B-二叉树给出先序中序构建二叉树.h"

BiTree reSturctTree(int postL, int postR, int inL, int inR) {
    if (postL > postR) return nullptr;
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    int index, numLeft;
    root->data = postOrderL[postR];      // 分配根节点

    // 中序遍历序列中找到后序序列相对应的根节点
    for (index = inL; index < inR; ++index) {
        if (postOrderL[postR] == inOrderL[index])
            break;
    }// 得到后序postR == 中序index
    numLeft = index - inL;
    root->lchild = reSturctTree(postL, postL + numLeft - 1, inL, index - 1);
    root->rchild = reSturctTree(postL + numLeft, postR - 1, index + 1, inR);

    return root;
}





//
// Created by 陈至宇 on 2022/5/23.
//

#ifndef ALGORITHMNOTESBUILDING_1020_给后序_中序_二叉树_输出层序遍历二叉树_H
#define ALGORITHMNOTESBUILDING_1020_给后序_中序_二叉树_输出层序遍历二叉树_H

#endif //ALGORITHMNOTESBUILDING_1020_给后序_中序_二叉树_输出层序遍历二叉树_H
