#include <iostream>
using namespace std;
// 二叉树重构

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTree(int* arr, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = createBinaryTree(arr, start, mid - 1);
    root->right = createBinaryTree(arr, mid + 1, end);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = createBinaryTree(arr, 0, n - 1);
    inorderTraversal(root);
    return 0;
}



//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_1_递归创建二叉树_H
#define ALGORITHMNOTESBUILDING_1_递归创建二叉树_H

#endif //ALGORITHMNOTESBUILDING_1_递归创建二叉树_H
