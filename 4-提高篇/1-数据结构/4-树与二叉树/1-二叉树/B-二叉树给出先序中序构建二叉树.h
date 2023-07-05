#include "A-二叉树定义.h"

using namespace std;

// preOrder:[preL, preR];; inOrder:[inL, inR];;

// restruct
/*BiTNode create_N(int preStart, int inStart, int inEnd, int *preOrder, int *inOrder) {
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    int index = 0;
    for (int i = inStart; i <= inEnd; ++i) { ;
    }
}*/

/*re-construction*/
BiTree create_H(int preL, int preR, int inL, int inR) {
    if (preL > preR) return nullptr;
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    int index, numLeft = 0;
    root->data = pre_OrderL[preL];    // root 根 左右 --先根遍历

    for (index = inL; index < inR; ++index) {   // 从中序 最左遍历到最右
        // 得到 先序index == 中序index
        if (pre_OrderL[preL] == in_OrderL[index]) // 此时 preL是可以递归得到的：：
            break;
    }// 得到 先序index == 中序index

    numLeft = index - inL;    // 左子树还剩多少个  -- 中序遍历来看
    // 左子树先序区间： [preL+1, preL+numLeft]， 中序[inL, index-1]
    // 返回左子树根结点地址， 赋值给temp根左指针
    root->lchild = create_H(preL + 1, preL + numLeft, inL, index - 1);
    root->rchild = create_H(preL + numLeft + 1, preR, index + 1, inR);

    return root;
}
//
// Created by 陈至宇 on 2022/3/14.
//

#ifndef ALGORITHMNOTESBUILDING_二叉树给出先序中序构建二叉树_H
#define ALGORITHMNOTESBUILDING_二叉树给出先序中序构建二叉树_H

#endif //ALGORITHMNOTESBUILDING_二叉树给出先序中序构建二叉树_H
