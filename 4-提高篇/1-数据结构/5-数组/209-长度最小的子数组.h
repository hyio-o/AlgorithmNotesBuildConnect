#include "../4-树与二叉树/1-二叉树/A-二叉树定义.h"

// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组
// ，并返回其长度。如果不存在符合条件的子数组，返回 0。

// 暴力递归方法
class force_Solu {
public:
    int minSubArrayLen(int length, vector<int> &nums) {
        int result = INT32_MIN; // 最终结果
        int sum = 0, subLength = 0; // 子序列数值和， 子序列长度
        for (int i = 0; i < nums.size(); ++i) { // 子序列起点 i
            sum = 0;
            for (int j = i; j < nums.size(); ++j) { // 子序列终止位置 j
                sum += nums[j];

            }
        }
    }
};

//
// Created by 陈至宇 on 2022/8/12.
//

#ifndef ALGORITHMNOTESBUILDING_209_长度最小的子数组_H
#define ALGORITHMNOTESBUILDING_209_长度最小的子数组_H

#endif //ALGORITHMNOTESBUILDING_209_长度最小的子数组_H
