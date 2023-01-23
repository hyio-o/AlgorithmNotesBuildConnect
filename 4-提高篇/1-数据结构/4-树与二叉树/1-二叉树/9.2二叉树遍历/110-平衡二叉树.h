#include "../A-二叉树定义.h"
//

// 1。从底部至顶

class Solution {
public:
    int original_f(BiTNode *root) {
        if (!root) return 0;
        int leftH = original_f(root->lchild);
        if (leftH == -1) return -1;
        int rightH = original_f(root->rchild);
        if (rightH == -1) return -1;

        int result;
        if (abs(leftH - rightH) > 1) result = -1;
        else {
            result = 1 + max(leftH, rightH);  //
        }
        return result;
    }

    int improvement(BiTNode *root) {
        int leftH = original_f(root->lchild);
        if (leftH == -1) return -1;
        int rightH = original_f(root->rchild);
        if (rightH == -1) return -1;
        return abs(leftH - rightH) > 1 ? -1 : 1 + max(leftH, rightH);
    }
};

//1-2  使用栈来模拟
class solution_Stack {
public:
    int getDepth(BiTNode *root) {
        stack<BiTNode *> st;
        if (root != NULL) st.push(root);
        int depth = 0, result = 0;
        while (!st.empty()) {
            BiTNode *temp = st.top();
            if (temp != NULL) {
                st.pop();
                st.push(temp);
                st.push(NULL);
                depth++;
                if (root->rchild) st.push(root->rchild);
                if (root->lchild) st.push(root->lchild);
            } else {
                st.pop();
                temp = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }
};


// 2。 从顶部至底



//
// Created by 陈至宇 on 2022/7/19.
//

#ifndef ALGORITHMNOTESBUILDING_110_平衡二叉树_H
#define ALGORITHMNOTESBUILDING_110_平衡二叉树_H

#endif //ALGORITHMNOTESBUILDING_110_平衡二叉树_H
