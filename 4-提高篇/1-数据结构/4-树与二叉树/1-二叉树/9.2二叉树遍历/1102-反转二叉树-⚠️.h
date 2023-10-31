#include "../../../0-初始化定义/4-二叉树定义.h"
#include "../../../0-初始化定义/3-队列定义.h"

/*法一： 递归思想*/
BiTree invertBTree_N(BiTNode *&root) {
    if (!root) return nullptr;

    BiTNode *temp = root->rchild;
    root->rchild = root->lchild;
    root->lchild = temp;

    invertBTree_N(root->lchild);
    invertBTree_N(root->rchild);

    return root;
}
/*法二： 动态转换？*/
/*法三： 静态转置*/
// 队列 - 迭代法 -- 层序
BiTree invertBTree_Se(BiTNode *&root) {
    SeQueue Se;

    if (root)
        enQueue(Se, root);

    while (!isEmptySe(Se)) {
        BiTNode *curr, *temp;
        deQueue(Se, curr);
        // swap l r
        temp = curr->lchild;
        curr->lchild = curr->rchild;
        curr->rchild = temp;

        if (curr->lchild) enQueue(Se, curr->lchild);
        if (curr->rchild) enQueue(Se, curr->rchild);
    }
    return root;
}


// 栈 - 迭代法  --深度DFS
BiTree invertBTree_Sq(BiTNode *&root) {
    if (!root) return nullptr;
    SqStack Sq;
    initStack(Sq);

    Push(Sq, root);
    while (!isEmptySq(Sq)) {
        BiTree curr;
        Pop(Sq, curr);

        BiTree temp = curr->lchild; // swap
        curr->lchild = curr->rchild;
        curr->rchild = temp;

        if (curr->rchild) Push(Sq, curr->rchild);
        if (curr->lchild) Push(Sq, curr->lchild);
    }

    return root;
}

//
// Created by 陈至宇 on 2022/6/5.
//

#ifndef INC_6C4CFE0C26A040D2AE8793A0871ECDBB
#define INC_6C4CFE0C26A040D2AE8793A0871ECDBB

#endif //INC_6C4CFE0C26A040D2AE8793A0871ECDBB
