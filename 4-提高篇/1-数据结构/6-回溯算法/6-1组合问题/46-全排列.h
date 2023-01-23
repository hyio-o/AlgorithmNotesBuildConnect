#include "../head.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == true) continue; // 已经使用过则跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);  // 装载nums元素，标记使用过否
        backtracking(nums, used);
        return result;
    }
};



//
// Created by 陈至宇 on 2022/9/26.
//

#ifndef ALGORITHMNOTESBUILDING_46_全排列_H
#define ALGORITHMNOTESBUILDING_46_全排列_H

#endif //ALGORITHMNOTESBUILDING_46_全排列_H
