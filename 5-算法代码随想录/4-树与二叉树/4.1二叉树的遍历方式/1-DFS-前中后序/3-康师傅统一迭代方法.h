#include "../../../0-初始化定义/4-二叉树定义.h"

class DMSXLsolution{
public:
	vector<int> inO(TreeNode* root){    // 左中右 左根右  比较难 🙁
		vector<int> result;
		stack<TreeNode *> st;
		if(root)    st.push(root);
		while(!st.empty())
		{
			TreeNode *cur = st.top();
			if(cur != NULL)
			{
				if(cur->right)  st.push(cur->right);    // 栈顺序 【右
				st.push(cur);   // 栈顺序 【右 中
				st.push(NULL);  // 栈顺序 【右 中 NULL        // 等待处理：
				if(cur->left)   st.push(cur->left);     // 栈顺序 【右 中 NULL 左
			}
			else{   // 只有在遇到空节点时，才将下一个节点放进结果集 result
				st.pop();       // 此时 cur == NULL， 可弹出 栈顺序中 NULL 【右 中 NULL(弹出准备)
				cur = st.top();
				st.pop();       // 此时 cur == 中， 再次的pop()操作表明 栈顺序只剩下 【右
				result.push_back(cur->val);
			}
		}
		return result;
	}

};



//
// Created by 陈至宇 on 2024/1/21.
//

#ifndef ALGORITHMNOTESBUILDING_3_康师傅统一迭代方法_H
#define ALGORITHMNOTESBUILDING_3_康师傅统一迭代方法_H

#endif //ALGORITHMNOTESBUILDING_3_康师傅统一迭代方法_H
