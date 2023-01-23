#include "../A-二叉树定义.h"
#include <unordered_map>

// 普通树
// 1-1 recursion_Solu : 使用map统计出现次数， 遍历序列是不重要的
class recursion_Solu {
private:
    // map<int, int> key:data, val:frequency
    void searchBST(BiTNode *root, unordered_map<int, int> &map) {
        if (!root) return;
        map[root->data]++;
        searchBST(root->lchild, map);
        searchBST(root->rchild, map);
        return;
    }

    bool static cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;  // 排序按频率大小
    }

public:
    vector<int> findMode(BiTNode *root) {
        unordered_map<int, int> map;    //key:  ;; value:
        vector<int> result;
        if (!root) return result;
        searchBST(root, map);   // 引用递归函数 绘制map 词频出现数组
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);  // sort cmp
        result.push_back(vec[0].first);
        for (int i = 0; i < vec.size(); ++i) {
            // 最高放在result
            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};
// 二叉搜索树 BST


//
// Created by 陈至宇 on 2022/8/17.
//

#ifndef ALGORITHMNOTESBUILDING_501_二叉搜索树的众数_H
#define ALGORITHMNOTESBUILDING_501_二叉搜索树的众数_H

#endif //ALGORITHMNOTESBUILDING_501_二叉搜索树的众数_H
