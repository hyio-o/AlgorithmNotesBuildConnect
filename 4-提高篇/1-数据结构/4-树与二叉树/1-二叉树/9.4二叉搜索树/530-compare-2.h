#include "../A-二叉树定义.h"

// 迭代法 ： 利用栈 ; 顺便线索化    ; 中序
class iterlation_Solu {
public:
    int findMinDiff(BiTNode *root) {
        stack<BiTNode *> stk;
        BiTNode *pre = NULL;
        BiTNode *index = root;
        int f_min = INT_MAX;
        while (!index || !stk.empty()) {
            if (!index) {
                stk.push(index);
                index = index->lchild;
            } else {
                index = stk.top();
                stk.pop();
                if (pre != NULL)
                    f_min = min(f_min, index->data - pre->data);
                pre = index;
                index = index->rchild;
            }
        }
        return f_min;
    }
};