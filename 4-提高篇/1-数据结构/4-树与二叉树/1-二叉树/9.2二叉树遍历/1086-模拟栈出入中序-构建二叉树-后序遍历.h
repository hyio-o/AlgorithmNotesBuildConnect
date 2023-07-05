// 输入时，进行递归建立二叉树
// 使用 先序+中序 构建二叉树的方法，先从输入输出栈元素得到
#include "../A-二叉树定义.h"
#include <cstdio>
#include <cstdlib>
#include <stack>
//#include <string>
#include <cstring>
//#include <iostream>

using namespace std;

Elemtype preOrderL[MMAXN], inOrderL[MMAXN];

void scanStackT() {
    int n, el, preIndex = 0, inIndex = 0;
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &el);
            preOrderL[preIndex++] = el;  // 作为根压入栈；
            st.push(el);
        } else {
            inOrderL[inIndex++] = st.top(); // pop : 从
            st.pop();
        }
    }
}


//
// Created by 陈至宇 on 2022/6/3.
//

#ifndef ALGORITHMNOTESBUILDING_1086_模拟栈出入中序_构建二叉树_后序遍历_H
#define ALGORITHMNOTESBUILDING_1086_模拟栈出入中序_构建二叉树_后序遍历_H

#endif //ALGORITHMNOTESBUILDING_1086_模拟栈出入中序_构建二叉树_后序遍历_H
