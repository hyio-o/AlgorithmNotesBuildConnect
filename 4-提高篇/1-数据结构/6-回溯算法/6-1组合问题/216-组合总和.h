// 回溯枚举方法，可不可以套用第一次组合算法的方法
/*找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明所有数字都是正整数。解集不能包含重复的组合。
示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]
示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]#*/
/*、方法论：
 * 1. 树形框架下，叶子（path.size()==k, startIndex找到了目标和targetSum == sum：： 就可以插入了
 * 2. 找叶子的步骤： */
#include "../head.h"

class Solution {
private:
    // targetSum：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == targetSum)
                result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= targetSum; ++i) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
    }
};
//
// Created by 陈至宇 on 2022/9/18.
//

#ifndef ALGORITHMNOTESBUILDING_216_组合总和_H
#define ALGORITHMNOTESBUILDING_216_组合总和_H

#endif //ALGORITHMNOTESBUILDING_216_组合总和_H
