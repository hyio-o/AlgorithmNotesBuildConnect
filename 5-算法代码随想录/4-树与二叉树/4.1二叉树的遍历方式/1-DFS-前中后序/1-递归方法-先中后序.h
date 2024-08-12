#include "../../../0-初始化定义/4-二叉树定义.h"
#include <vector>

// 前序遍历：中左右
// 中序遍历：左中右
// 后序遍历：左右中

class solution{
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}

private:
	void traversal(TreeNode *cur, vector<int>& vec){
		if (cur == NULL)    return;
		vec.push_back(cur->val);    // 中   vist
		traversal(cur->left, vec);  // 左
		traversal(cur->right, vec); // 右
	}
};



//
// Created by 陈至宇 on 2024/1/20.
//

#ifndef ALGORITHMNOTESBUILDING_1_递归方法_先中后序_H
#define ALGORITHMNOTESBUILDING_1_递归方法_先中后序_H

#endif //ALGORITHMNOTESBUILDING_1_递归方法_先中后序_H
