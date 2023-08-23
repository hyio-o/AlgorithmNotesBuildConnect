#include "../1-数组定义.h"

class Solution{
public:
    string replaceSpace(string S)
    {
        int count_space = 0; // 空格计数
        int size_oldS = S.size();   // 老长度
        // 计数 空格
        for (int i = 0; i < S.size(); ++i) {
            if(S[i] == ' ') count_space++;
        }
        // 扩充长度
        S.resize(S.size() + (count_space * 2)); // 原来是一个， 后面要多加 2n 个，x -> xxx
        int size_newS = S.size();
        // 替换 new_r , old_r  :rear
        for (int new_r = size_newS-1, old_r = size_oldS-1; old_r < new_r   ; old_r--, new_r--) {
            // 老尾巴指向要替换的值，（如果老尾巴是空格，那么该填替换值了；如果是老尾巴是值，把值传递给新尾巴）
            if(S[old_r] != ' '){
                S[new_r] = S[old_r];
            }
            else{
                S[new_r] = '0';
                S[new_r-1] = '2';
                S[new_r-2] = '%';
                new_r -= 2;
            }
        }
        return S;
    }
};


/*
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
如果想把这道题目做到极致，就不要只用额外的辅助空间了！

1. 首先扩充数组到每个空格替换成"%20"之后的大小。

2. 然后从后向前替换空格，也就是双指针法，过程如下：

i指向新长度的末尾，j指向旧长度的末尾。
#
 * */
//
// Created by 陈至宇 on 2023/8/8.
//
