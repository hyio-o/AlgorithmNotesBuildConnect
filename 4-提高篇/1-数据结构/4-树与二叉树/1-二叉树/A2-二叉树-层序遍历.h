#include "A-二叉树定义.h"

void LayerOrder(BiTNode *T) {
    SeQueue Se;
    BiTNode *p = T;
    enQueue(Se, p);
    while (!isEmptySe(Se)) {
        deQueue(Se, p);
        visit(p);
        if (p->lchild) enQueue(Se, p->lchild);
        if (p->rchild) enQueue(Se, p->rchild);
    }
}


//
// Created by 陈至宇 on 2022/5/28.
//

#ifndef ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H
#define ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H

#endif //ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H
