#include "0-基本函数库.h"

class Solutions{
public:
    void bubbleSort(vector<int>& nums){
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = 0; j < nums.size() - i - 1; ++j) {
                if(nums[j] > nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
    }

private:
    void swap(int &a, int &b) {
        if (a == b) {
            int temp = a;
            a = b;
            b = temp;
        } else {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
    }
};


//
// Created by 陈至宇 on 2023/9/16.
//

#ifndef ALGORITHMNOTESBUILDING_6_1_2_1_交换排序_冒泡排序_H
#define ALGORITHMNOTESBUILDING_6_1_2_1_交换排序_冒泡排序_H

#endif //ALGORITHMNOTESBUILDING_6_1_2_1_交换排序_冒泡排序_H
