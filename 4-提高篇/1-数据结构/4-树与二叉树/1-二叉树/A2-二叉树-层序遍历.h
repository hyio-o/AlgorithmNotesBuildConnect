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


// 迭代法 -- 层序遍历
class solution_level {
public:
    int maxDepth(BiTNode *root) {
        if (!root) return 0;
        int depth = 0;
        queue<BiTNode *> Se;
        Se.push(root);
        while (!Se.empty()) {
            int size = Se.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                BiTNode *temp = Se.front();
                Se.pop();
                if (temp->lchild) Se.push(temp->lchild);
                if (temp->rchild) Se.push(temp->rchild);
            }
        }
        return depth;
    }
};


//
// Created by 陈至宇 on 2022/5/28.
//

#ifndef ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H
#define ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H

#endif //ALGORITHMNOTESBUILDING_A_二叉树_层序遍历_H
