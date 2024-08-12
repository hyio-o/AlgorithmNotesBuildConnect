#include "../../../0-初始化定义/4-二叉树定义.h"
#include <vector>

class solution {
public:
	int getdepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftdepth = getdepth(node->left);       // 左
		int rightdepth = getdepth(node->right);     // 右

		int depth = 1 + max(leftdepth, rightdepth); // 中
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getdepth(root);
	}
};






//
// Created by 陈至宇 on 2024/1/22.
//

#ifndef ALGORITHMNOTESBUILDING_1_递归_最大深度_H
#define ALGORITHMNOTESBUILDING_1_递归_最大深度_H

#endif //ALGORITHMNOTESBUILDING_1_递归_最大深度_H
