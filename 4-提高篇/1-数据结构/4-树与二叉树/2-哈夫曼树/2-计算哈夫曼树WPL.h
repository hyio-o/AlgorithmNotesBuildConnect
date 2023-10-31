#include "../../0-初始化定义/4-二叉树定义.h"

// restruct BiTNode
typedef struct HTNode {
    Elemtype data;
    int weight;
    struct BiTNode *lchild, *rchild;
} HTNode, *HTTree;


int WPLrec(HTNode* lbt,int n)
{
    int wpl = 0;
    if (lbt != NULL)
    {
        if (lbt->lchild == NULL && lbt->rchild == NULL)
            wpl += n * lbt->weight;
        wpl += WPLrec(lbt->lchild, n + 1);
        wpl += WPLrec(lbt->rchild, n + 1);
    }
    return wpl;
}




//
// Created by 陈至宇 on 2023/10/30.
//

#ifndef ALGORITHMNOTESBUILDING_2_计算哈夫曼树WPL_H
#define ALGORITHMNOTESBUILDING_2_计算哈夫曼树WPL_H

#endif //ALGORITHMNOTESBUILDING_2_计算哈夫曼树WPL_H
