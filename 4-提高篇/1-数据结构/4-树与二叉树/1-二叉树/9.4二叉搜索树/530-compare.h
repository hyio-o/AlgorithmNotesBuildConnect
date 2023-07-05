#include "../A-二叉树定义.h"

class Solution {
public:
    int getMinimumDifference(BiTNode *root) {
        stack<BiTNode* > st;
        BiTNode *cur = root;
        BiTNode *pre = NULL;
        int result = INT_MAX;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur);    // 将访问的节点放进栈
                cur = cur->lchild; // 左
            } else {
                cur = st.top();
                st.pop();
                if (pre != NULL) { // 中
                    result = min(result, cur->data - pre->data);
                }
                pre = cur;
                cur = cur->rchild; // 右
            }
        }
        return result;
    }
};