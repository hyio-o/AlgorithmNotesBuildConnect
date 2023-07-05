#include "../A-二叉树定义.h"
//#include "../A1-二叉树-遍历-先中后.h"
//#include "../A2-二叉树-层序遍历.h"

//typedef int Elemtype;
//const int MMAXN = 1000;
//Elemtype preOrderL[MMAXN], inOrderL[MMAXN], postOrderL[MMAXN];


/*re-construction*/
BiTree create_H(int preL, int preR, int inL, int inR) {
    if (preL > preR) return nullptr;
    BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
    int index, numLeft = 0;
    temp->data = pre_OrderL[preL];    // temp 根 左右 --先根遍历
    BiTNode *root = temp;

    for (index = inL; index < inR; ++index) {   // 从中序 最左遍历到最右
        // 得到 先序index == 中序index
        if (pre_OrderL[preL] == in_OrderL[index]) // 此时 preL是可以递归得到的：：
            break;
    }// 得到 先序index == 中序index

    numLeft = index - inL;    // 左子树还剩多少个  -- 中序遍历来看
    // 左子树先序区间： [preL+1, preL+numLeft]， 中序[inL, index-1]
    // 返回左子树根结点地址， 赋值给temp根左指针
    temp->lchild = create_H(preL + 1, preL + numLeft, inL, index - 1);
    temp->rchild = create_H(preL + numLeft + 1, preR, index + 1, inR);

    return root;
}

void preOrder(BiTree T) {
    if (!T) return;
    visit(T);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void inOrder(BiTree T) {
    if (!T) return;
    inOrder(T->lchild);
    visit(T);
    inOrder(T->rchild);
}

void postOrder(BiTree T) {
    if (!T) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    visit(T);
}


//
// Created by 陈至宇 on 2022/6/3.
//

#ifndef ALGORITHMNOTESBUILDING_ANTI_1020_先序_中序_输出层序或后序_H
#define ALGORITHMNOTESBUILDING_ANTI_1020_先序_中序_输出层序或后序_H

#endif //ALGORITHMNOTESBUILDING_ANTI_1020_先序_中序_输出层序或后序_H
