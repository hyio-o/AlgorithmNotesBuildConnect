#include "0-基本函数库.h"

class solution{
public:
    vector<int> selectSort(vector<int>& nums)
    {// 假定为升序排列，从小到大， 每次的选择最小值
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int index_min = i;    // 最小值的地址
            for (int j = i+1; j < length; ++j)
            {   // 找最小
                if(nums[j] < nums[index_min])   index_min = j;
            }
            //helpFunc.swap_vector(nums[index_min], nums[i]);
            //mySwap(&nums[index_min], &nums[i]);
            swap(nums[index_min], nums[i]);
        }
    }
private:
    ANSolution helpFunc;
    void SelectSort(SqList *L) {
        int len = L->length;
        int minIndex, temp;
        for (int i = 0; i < len - 1; ++i) {
            minIndex = i;
            for (int j = i + 1; j < len; ++j) {   // 找最小 TODO 测试选择排序 i j的执行范围
                if (L->data[j] < L->data[minIndex])
                    minIndex = j;
            }
            temp = L->data[i];
            L->data[i] = L->data[minIndex];
            L->data[minIndex] = temp;
        }

    }

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
// Created by 陈至宇 on 2022/5/10.
//

#ifndef ALGORITHMNOTESBUILDING_2_1_选择排序_H
#define ALGORITHMNOTESBUILDING_2_1_选择排序_H

#endif //ALGORITHMNOTESBUILDING_2_1_选择排序_H
