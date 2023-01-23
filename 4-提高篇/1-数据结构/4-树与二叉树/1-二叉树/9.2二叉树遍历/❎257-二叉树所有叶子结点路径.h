#include "../A-二叉树定义.h"

//using namespace std;
/*两种方法， 1。使用递归，回溯结点路径*/
// 1。
class Solution {
private:

    void traversal(BiTNode *root, vector<int> &path, vector<string> &result) {
        path.push_back(root->data);
        if (root->lchild == NULL && root->rchild == NULL) { // 叶子结点
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i) {
                sPath += to_string(path[i]);    // to_string 函数:将数字常量转换为字符串
                sPath += "->";
            }
            sPath += to_string(path[path.size()] - 1);
            result.push_back(sPath);
            return;
        }
        if (root->lchild) {
            traversal(root->lchild, path, result);
            path.pop_back();    // 回溯
        }
        if (root->rchild) {
            traversal(root->rchild, path, result);
            path.pop_back();
        }

    }

public:

    vector<string> binaryTreePaths(BiTNode *root) {
        vector<string> result;
        vector<int> path;
        if (!root) return result;
        traversal(root, path, result);
        return result;
    }
};


//
// Created by 陈至宇 on 2022/7/21.
//

#ifndef ALGORITHMNOTESBUILDING_257_二叉树所有叶子结点路径_H
#define ALGORITHMNOTESBUILDING_257_二叉树所有叶子结点路径_H

#endif //ALGORITHMNOTESBUILDING_257_二叉树所有叶子结点路径_H
