#include "../../../0-初始化定义/4-二叉树定义.h"
// 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

// 如果转化成数组， 那么就是在有序数组中的最小值， 算法复杂度可以在 O(n):
//  相对小的是 祖先 - 左右孩子
// 递归： 转为数组， 再求最小绝对值
class recursion_Solu {
    vector<int> que;
private:
    void traversal(BiTNode *root) {
        if (!root) return;
        traversal(root->lchild);
        que.push_back(root->data);
        traversal(root->rchild);
    }

public:
    int findMinAbs(BiTNode *root) {
        que.clear();    // 重置 que数组
        traversal(root);
        if (que.size() < 2) return 0;
        int f_min = INT_MAX;
        /*for (int i = 0; i < que.size()-1; ++i) {
            if(abs(que[i] - que[i+1]) < f_min)
                f_min = que[i] - que[i+1];
        }*/
        for (int i = 0; i < que.size() - 1; ++i) {
            f_min = min(f_min, que[i + 1] - que[i]);
        }
        return f_min;
    }
};


// 中序线索化
class clue_Solu {
    vector<int> que;
    int f_min = INT_MAX;
    BiTNode *pre;
private:
    void traversal(BiTNode *root) {
        if (!root) return;
        traversal(root->lchild);
        if (!pre)
            f_min = min(root->data - pre->data, f_min);
        pre = root;
        traversal(root->rchild);
    }

public:
    int findMinDiff(BiTNode *root) {
        que.clear();
        traversal(root);
        return f_min;
    }
};


// 迭代法 ： 利用栈 ; 顺便线索化    ; 中序
class iterlation_Solu {
public:
    int findMinDiff(BiTNode *root) {
        stack<BiTNode *> stk;
        BiTNode *pre = NULL;
        BiTNode *index = root;
        int f_min = INT_MAX;
        while (!index || !stk.empty()) {
            if (!index) {
                stk.push(index);
                index = index->lchild;
            } else {
                index = stk.top();
                stk.pop();
                if (pre != NULL)
                    f_min = min(f_min, index->data - pre->data);
                pre = index;
                index = index->rchild;
            }
        }
        return f_min;
    }
};

//
// Created by 陈至宇 on 2022/8/14.
//

#ifndef ALGORITHMNOTESBUILDING_530_二叉搜索树的最小绝对值_H
#define ALGORITHMNOTESBUILDING_530_二叉搜索树的最小绝对值_H

#endif //ALGORITHMNOTESBUILDING_530_二叉搜索树的最小绝对值_H
