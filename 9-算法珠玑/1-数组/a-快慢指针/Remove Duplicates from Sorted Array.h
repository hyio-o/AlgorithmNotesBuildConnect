#include "../../headd.h"

// Remove Duplicates from Sorted Array
// Time Complexity: O(n)，Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow+1;
    }
};

/*使用双指针的方法
 * 已经排好序的数组 vector
 * slow， fast；
 * 1 1 2 3 3 4 5
 * 如果fast和slow是对等的值， 让fast 覆盖 slow ；
 * 如果不对等，////////////
 * */


//
// Created by 陈至宇 on 2023/6/12.
//

#ifndef ALGORITHMNOTESBUILDING_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define ALGORITHMNOTESBUILDING_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#endif //ALGORITHMNOTESBUILDING_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
