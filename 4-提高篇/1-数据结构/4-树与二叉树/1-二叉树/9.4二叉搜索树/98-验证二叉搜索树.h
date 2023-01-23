#include "../A-二叉树定义.h"
//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
/*判定特征：
 * 节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。 * */

// 递归： 中序遍历下单纯判断序列是否是增序； 但是在递归中比较难实现，因此增加一个数组存放中序序列
class recursion_Solu {
private:
    vector<int> squ;    // vector<int> &etc ??? 这是啥意思
    void traversal(BiTNode *root) {
        if (!root) return;
        traversal(root->lchild);
        squ.push_back(root->data);
        traversal(root->rchild);
    }

public:
    bool isBST(BiTNode *root) {
        traversal(root);
        for (int i = 0; i < squ.size() - 1; ++i) {
            if (squ[i] > squ[i + 1]) return false;
            else continue;
        }
        return true;
    }
};

/*
 * private:
    private:
    vector<int> squ;    // vector<int> &etc ??? 这是啥意思
    void traversal(TreeNode *root){
        if(!root)   return;
        traversal(root->left);
        squ.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isBST(TreeNode *root){
        traversal(root);
        for (int i = 0; i < squ.size()-1; ++i) {
            if(squ[i] > squ[i+1])   return false;
            else continue;
        }
        return true;
    }
 * */

//
// Created by 陈至宇 on 2022/8/13.
//

#ifndef ALGORITHMNOTESBUILDING_98_验证二叉搜索树_H
#define ALGORITHMNOTESBUILDING_98_验证二叉搜索树_H

#endif //ALGORITHMNOTESBUILDING_98_验证二叉搜索树_H
