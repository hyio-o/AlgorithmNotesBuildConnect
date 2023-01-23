#include "../A-二叉树定义.h"

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        int result = INT_MAX;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur);    // 将访问的节点放进栈
                cur = cur->left; // 左
            } else {
                cur = st.top();
                st.pop();
                if (pre != NULL) { // 中
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right; // 右
            }
        }
        return result;
    }
};