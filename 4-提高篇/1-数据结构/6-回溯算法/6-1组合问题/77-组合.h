#include "../head.h"
//示例:输入: n = 4, k = 2输出:[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
/*给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。*/

class Solution {
private:
    vector<vector<int>> result; // result - 结果
    vector<int> path;   // path - 路径
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);  //
            backtracking(n, k, i + 1); //recursive
            path.pop_back();    // 回溯，撤销处理节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(4, 3, 0);
        return result;
    }
};
//
// Created by 陈至宇 on 2022/9/11.
//

#ifndef ALGORITHMNOTESBUILDING_77_组合_H
#define ALGORITHMNOTESBUILDING_77_组合_H

#endif //ALGORITHMNOTESBUILDING_77_组合_H
