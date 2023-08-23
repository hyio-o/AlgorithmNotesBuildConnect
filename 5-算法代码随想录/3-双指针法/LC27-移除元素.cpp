#include "../1-数组定义.h"
// 1. force
class Sol_2{
public:
    int removeEle(vector<int>& nums, int val)
    {
        int size_nums = nums.size();
        for (int i = 0; i < size_nums; ++i)
        {
            if(val == nums[i])  // 找到元素， 整体迁移 成 ：稳态
            {   // 从前面往后面移动 i -> size_nums
                for (int j = i+1; j < size_nums; ++j) {
                    nums[j-1] = nums[j];
                }
            }
            i--;
            size_nums = size_nums - 1;
        }
        return size_nums;
    }
};

// 2. 双指针
class Sol_1{
public:
    int removeElem(vector<int>& nums, int val)
    {
        int index_slow = 0;
        for (int index_fast = 0; index_fast < nums.size(); ++index_fast) {
            if(val == nums[index_fast]){
                nums[index_slow] = nums[index_fast];
                index_slow++;
            }
        }
        return index_slow;
    }
};

//
// Created by 陈至宇 on 2023/8/7.
//
