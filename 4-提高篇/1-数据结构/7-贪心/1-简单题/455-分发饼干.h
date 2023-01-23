#include "../head.h"
// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
// 但是，每个孩子最多只能给一块饼干。
/*
 * 对每个孩子 i，都有一个胃口值 g[i]，
 * 这是能让孩子们满足胃口的饼干的最小尺寸；
 * 并且每块饼干 j，都有一个尺寸 s[j] 。
 * 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，
 * 这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 * */

// 思路：不要造成饼干浪费，则应该优先满足胃口大的
// 这里的局部最优就是大饼干喂给胃口大的，充分利用饼干尺寸喂饱一个，
// *      全局最优就是喂饱尽可能多的小孩。
//
/* 1. 先饼干数组、孩子数组 ：：排序
 * 2. 然后从后向前遍历小孩数组，用大饼干优先满足胃口大的，并统计满足小孩数量。
 * */

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) { // g: people s:biscuit
        // 1. sort
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 2. feed
        int index = s.size() - 1; // 饼干从大到小，填充孩子胃口从大到小
        int result = 0; // 能填饱肚子的孩子个数
        for (int i = g.size() - 1; i >= 0; --i) { // 孩子倒序; 流水的孩子，铁打的饼干
            if (index >= 0 && s[index] >= g[i]) {  // 饼干还有 && 饼干能够填饱孩子的肚子（非拆饼干）
                result++;
                index--;
            }
        }
        return result;
    }
};


// 方法二； 小饼干先喂饱小胃口
class solution2 {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 1. sort
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 2. feed
        int index = 0;  // 孩子
        for (int i = 0; i < s.size(); ++i) {    // 饼干从小到大轮巡
            if (index < g.size() && g[index] <= s[i]) index++;
        }
        return index;
    }

};
//
// Created by 陈至宇 on 2022/10/7.
//

#ifndef ALGORITHMNOTESBUILDING_455_分发饼干_H
#define ALGORITHMNOTESBUILDING_455_分发饼干_H

#endif //ALGORITHMNOTESBUILDING_455_分发饼干_H

/*示例 1:

输入: g = [1,2,3], s = [1,1]
输出: 1 解释:你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。所以你应该输出1。
示例 2:

输入: g = [1,2], s = [1,2,3]
输出: 2
解释:你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。你拥有的饼干数量和尺寸都足以让所有孩子满足。所以你应该输出2.
提示：

1 <= g.length <= 3 * 10^4
0 <= s.length <= 3 * 10^4
1 <= g[i], s[j] <= 2^31 - 1
#*/