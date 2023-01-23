// 找到树的最底下一行， 然后输出其最左边的值

// 层序遍历，知道为最下一层时，输出第一个遍历的元素就是
// 递归方法：最后一行：深度最大的叶子节点一定是最后一行；前序遍历
// 递归返回值问题：  如果需要遍历整棵树，递归函数就不能有返回值。
//                如果需要遍历某一条固定路线，递归函数就一定要有返回值！
#include <climits>
#include "../A-二叉树定义.h"

/*
 * 递归：
 * 1。 确定递归条件： 最大深度maxLen， 最大深度最左结点数值maxLeftVal；
 * 2。 确定终止条件： 当为叶子结点时统计最大深度，若未有遍历完成则继续记录maxLen与maxLeftVal；
 * 3。 确定单层递归逻辑： 深度回溯，形如二叉树最大深度 T-104
 * */

class Solution {
public:
    int maxLen = INT_MIN;
    int maxLeftVal;

    void traversal(BiTNode *root, int leftLen) {
        // 递归先序遍历， 左子树深度 更新 ;;
        if (root->lchild == NULL && root->rchild == NULL) {
            // 递归终止条件
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxLeftVal = root->data;
            }
            return;
        }
        if (root->lchild != NULL) traversal(root->lchild, leftLen + 1);
        if (root->rchild != NULL) traversal(root->rchild, leftLen + 1);
        return;
        /* 等价于一以下；
         if(root->lchild){
            depth++;
            getDepth_Pre(root->lchild, depth);
            depth--;
        }
        if(root->rchild){
            depth++;
            getDepth_Pre(root->rchild, depth);
            depth--;
        }
         * */
    }

    int findBottomLeftVal(BiTNode *root) {
        traversal(root, 0);
        return maxLeftVal;
    }
};

// 层序-模板
class iteration {
public:
    int maxLen = 0;
    int maxLeftVal;

    int findBottomLeftVal(BiTNode *root) {
        queue<BiTNode *> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            maxLen++;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                BiTNode *temp = que.front();
                que.pop();
                if (i == 0) return maxLeftVal = temp->data;
                if (temp->lchild) que.push(temp->lchild);
                if (temp->rchild) que.push(temp->rchild);
            }
        }
        return maxLeftVal;
    }
};

//
// Created by 陈至宇 on 2022/8/9.
//

#ifndef ALGORITHMNOTESBUILDING_513_找到树左下角的值_H
#define ALGORITHMNOTESBUILDING_513_找到树左下角的值_H

#endif //ALGORITHMNOTESBUILDING_513_找到树左下角的值_H
