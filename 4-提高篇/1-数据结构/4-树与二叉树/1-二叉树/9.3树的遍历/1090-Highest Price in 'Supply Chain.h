#include "../A-二叉树定义.h"
//给出一棵销售供应的树，树根唯一。在树根处货物的价格为P，
// 然后从根结点开始每往子结点走一层，该层的货物价格将会在父亲结点的价格上增加r%。
// 求所有叶结点中的最高价格以及这个价格的叶结点个数。

vector<int> child[MMAXN];    // reserve tree;
double p, r;
int n, maxDepth = 0, num = 0;   // maxDepth, num:最大深度叶结点个数
void DFS(int index, int depth) {
    if (child[index].size() == 0) {   // 到达叶结点
        if (depth > maxDepth) {       // index深度比之前记录深度长，
            // 更新最大深度，重置最大深度叶结点个数为1
            maxDepth = depth;
            num = 1;
        } else if (depth == maxDepth) // index深度 == 之前记录深度长
            num++;
        else;
        return;
    }
    for (int i = 0; i < child[index].size(); ++i) {
        DFS(child[index][i], depth + 1);  // recursive indedx
    }
}

/*
 * 递归边界。当结点index的子结点个数为0时，表示到达了叶结点。
 * 此时判断当前深度depth是否大于最大深度maxDepth，如果大于，
 * 则更新maxDepth并重置num为1；如果不大于，则判断depth是否等于maxDepth，
 * 如果depth等于maxDepth，则令num++，表示最大深度的结点个数加1。
递归式。对index的所有子结点进行递归，同时深度depth加1。
 * */
//
// Created by 陈至宇 on 2022/6/6.
//

#ifndef ALGORITHMNOTESBUILDING_1090_HIGHEST_PRICE_IN_SUPPLY_CHAIN_H
#define ALGORITHMNOTESBUILDING_1090_HIGHEST_PRICE_IN_SUPPLY_CHAIN_H

#endif //ALGORITHMNOTESBUILDING_1090_HIGHEST_PRICE_IN_SUPPLY_CHAIN_H
