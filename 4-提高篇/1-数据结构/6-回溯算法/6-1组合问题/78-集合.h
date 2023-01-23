#include "../head.h"

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex) {
        result.push_back(path); // 不放在上面会漏掉自己；❎
        if (startIndex >= nums.size())
            return;
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subSets(vector<int> &nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

//
// Created by 陈至宇 on 2022/9/26.
//

#ifndef ALGORITHMNOTESBUILDING_78_集合_H
#define ALGORITHMNOTESBUILDING_78_集合_H

#endif //ALGORITHMNOTESBUILDING_78_集合_H
