// recurse
#include "../A-二叉树定义.h"

class Solution_1 {
private:
    int getBiTNodesNum(BiTNode *root) {
        if (!root) return 0;
        int leftNum = getBiTNodesNum(root->lchild);
        int rightNum = getBiTNodesNum(root->rchild);
        int sumNum = leftNum + rightNum + 1;
        return sumNum;
    }

public:
    int countBiTNodes(BiTNode *root) {
        return getBiTNodesNum(root);
    }
};


// DIe -- 也是计算整棵树的所有结点的方法（二叉树）
class Solution_2 {
public:
    int countNum(BiTNode *root) {
        if (!root) return 0;
        queue<BiTNode *> Se;
        int sumNum = 0;
        Se.push(root);
        while (!Se.empty()) {
            BiTNode *temp = Se.front();
            Se.pop();
            if (root->lchild) Se.push(root->lchild);
            if (root->rchild) Se.push(root->rchild);
            sumNum++;
        }
    }
};

//
// Created by 陈至宇 on 2022/7/19.
//

#ifndef ALGORITHMNOTESBUILDING_222_完全二叉树的节点个数_H
#define ALGORITHMNOTESBUILDING_222_完全二叉树的节点个数_H

#endif //ALGORITHMNOTESBUILDING_222_完全二叉树的节点个数_H
