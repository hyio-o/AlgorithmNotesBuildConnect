#include "../../../0-初始化定义/4-二叉树定义.h"

// 本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。
// Pre-order 从上到下、/
int getDepth(BiTree root) {
    if (root == NULL) return 0;
    int left_depth = getDepth(root->lchild);
    int right_depth = getDepth(root->rchild);
    int depth = 1 + max(left_depth, right_depth);
    return depth;
}

// re-arrange
int getDepth_H(BiTNode *root) {
    if (root == NULL) return 0;
    return 1 + max(getDepth_H(root->lchild), getDepth_H(root->rchild));
}

// pre-order -- 从下到上
class solution {
public:
    int result;

    void getDepth_Pre(BiTNode *root, int depth) {
        result = depth > result ? depth : result;
        if (root->lchild == NULL && root->rchild == NULL) return;
        // 为什么要回溯：先序遍历，
        if (root->lchild) {
            depth++;
            getDepth_Pre(root->lchild, depth);
            depth--;
        }
        if (root->rchild) {
            depth++;
            getDepth_Pre(root->rchild, depth);
            depth--;
        }
        return;
    }

    int maxDepth(BiTree root) {
        result = 0;
        if (root == NULL) return result;
        getDepth_Pre(root, 1);
        return result;
    }
};

// re-arrange
class solution_pre {
public:
    int result;

    void getDepth_Pre(BiTNode *root, int depth) {
        result = depth > result ? depth : result;
        if (root->lchild == NULL && root->rchild == NULL) return;
        if (root->lchild)
            getDepth_Pre(root->lchild, depth + 1);
        if (root->rchild)
            getDepth_Pre(root->rchild, depth + 1);
        return;
    }

    int maxDepth(BiTNode *root) {
        result = 0;
        if (root == NULL) return result;
        getDepth_Pre(root, 1);
        return result;
    }
};


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
// Created by 陈至宇 on 2022/7/13.
//

#ifndef ALGORITHMNOTESBUILDING_104_二叉树最大深度_H
#define ALGORITHMNOTESBUILDING_104_二叉树最大深度_H

#endif //ALGORITHMNOTESBUILDING_104_二叉树最大深度_H
