#include <vector>

using namespace std;

// slowIndex 的移动根据 val != index ;; fastIndex 的移动根据 index < nums.size()；
// 代差是 val == index 时， slowIndex 被后面的 val != index  nums[fastIndex] 所覆盖
int removeElem(vector<int> &nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
        if (val != nums[fastIndex])
            nums[slowIndex++] = nums[fastIndex];
    }
    return slowIndex;
}

// 双向 双指针
int remElem(vector<int> &nums, int val) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;    // 逻辑量转换为地址下表的实际量；
    while (leftIndex <= rightIndex) {
        // 找 leftIndex == val, 且在左边
        while (leftIndex <= rightIndex && nums[leftIndex] != val)
            ++leftIndex;
        // 找 rightIndex != val, 且在右边 ||| 若就是最后一个元素val，则不执行循环， rightIndex = nums.size() -1;
        while (leftIndex <= rightIndex && nums[rightIndex] == val)
            --rightIndex;
        // 将右边不等于val的元素覆盖左边等于val的元素
        if (leftIndex < rightIndex)
            nums[leftIndex++] = nums[rightIndex--];

    }
}




//
// Created by 陈至宇 on 2022/7/14.
//

#ifndef ALGORITHMNOTESBUILDING_27_移除元素_快慢指针法_H
#define ALGORITHMNOTESBUILDING_27_移除元素_快慢指针法_H

#endif //ALGORITHMNOTESBUILDING_27_移除元素_快慢指针法_H
