#include "0-基本函数库.h"



// F1
class Solution {
public:
// F1 InsertSort
    vector<int> sortArray(vector<int>& nums) {
        int i, j, key;
        for(i=1; i < nums.size(); i++)
        {
            key = nums[i];  //alies
            j = i;
            while(j > 0 && key < nums[j-1]){
                swap(nums[j-1], nums[j]);
                j--;
            }
            nums[j] = key;
        }
        return nums;
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

// F2-折半插入排序
void BInsertSort(SqList *L) {
    int i, j, m, low, high;
    for (int i = 2; i < L->length; ++i) {
        L->data[0] = L->data[i];    //
        low = 1;
        high = i - 1;        //
        while (low < high) {
            m = (low + high) / 2;       //
            if (L->data[0] < L->data[m])   // 折半判定插入位
                high = m - 1;
            else
                low = m + 1;
        }
        for (int j = i - 1; j > high + 1; j--) {
            L->data[j + 1] = L->data[j];  //后移
        }
        L->data[high + 1] = L->data[0];   //插入
    }
}

//
// Created by 陈至宇 on 2022/5/9.
//

#ifndef ALGORITHMNOTESBUILDING_1_1_插入排序_直接插排_H
#define ALGORITHMNOTESBUILDING_1_1_插入排序_直接插排_H

#endif //ALGORITHMNOTESBUILDING_1_1_插入排序_直接插排_H
