#include "0-基本函数库.h"

// 1. 数组式 我就是试试233333333
class shellSortSolution{
public:
    vector<int> shellSort_finalVersion(vector<int>& nums)
    {
        int length = nums.size();
        int temp, index_front, index_rear;
        for (int step = length/2; step > 0; step /= 2) {
            for (index_rear = step; index_rear < length; index_rear++) {
                temp = nums[index_rear];
                index_front = index_rear - step;
                while (index_front >=0 && nums[index_front] > temp)
                {
                    nums[index_front+step] = nums[index_front];
                    index_front -= step;
                }
                nums[index_front+step] = temp;
            }
        }
        return nums;
    }
    void shellSort(vector<int>& nums)
    {
        int length = nums.size();
        if (length <= 1) {
            return; // 没有需要排序的元素
        }

        for (int step = length / 2; step >= 1; step /= 2) {
            shellInsertionSort(nums, step);
        }
    }
    vector<int> shellSort_sixth(vector<int>& nums)
    {
        int length = nums.size();
        int temp, index_front, index_rear;
        for (int step = length/2; step > 0; step /= 2) {
            for (index_rear = step; index_rear < length; index_rear++) {
                temp = nums[index_rear];
                index_front = index_rear - step;
                while (index_front >=0 && nums[index_front] > temp)
                {
                    nums[index_front+step] = nums[index_front];
                    index_front -= step;
                }
                nums[index_front+step] = temp;
            }
        }
        return nums;
    }

    vector<int> shellSort_replaseV(vector<int>& nums)
    {
        // int A[8] = { 8, 3, 5, 1, 4, 2, 7, 6 };
        //              0, 1, 2, 3, 4, 5, 6, 7
        int length = nums.size();
        int i, j, temp;
        for (int step = length/2 ; step > 0 ; step /= 2)    // step: 4->2->1-》
        {
            for (i = step; i < length; ++i) // i:4、5、6、7->2、3、4、5、6、7->1、2、3、4、5、6、7-》
            {
                temp = nums[i]; // temp:4、2、7、6->5、1、4、2、7、6->8、3、5、1、4、2、7、6-》
                j = i - step;   // j: 0、1、2、3->0、1、2、3、4、5->0、1、2、3、4、5、6-》
                // 首次的 j+step = i ， 其后的j+step =
                while (j >= 0 && nums[j] > step)
                {
                    nums[j + step] = nums[j];
                    j -= step;
                }
                nums[j + step] = temp;
            }
        }
        return nums;
    }
private:
    void shellInsertionSort(vector<int>& nums, int step) {
        int length = nums.size();
        for (int i = step; i < length; ++i) {
            int temp = nums[i];
            int j = i - step;
            while (j >= 0 && nums[j] > temp) {
                nums[j + step] = nums[j];
                j -= step;
            }
            nums[j + step] = temp;
        }
    }

};
vector<int> shellSort(vector<int>& nums)
{
    int i, j, temp;
    // 定义增量序列
    int gap = (nums.size() / 2);
    // shellSort
    while(gap > 0)
    {
        // 对每个分组进行插入排序
        for(i = gap; i < nums.size(); i++)
        {
            temp = nums[i];
            j = i;
            // 在当前分组内进行插入排序
            while(j >= gap && nums[j-gap] > temp){
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
        // 缩小增量序列 log₂(gap)
        gap /= 2;
    }
    return nums;
}

void shellSort_third(vector<int>& nums)
{
    int length = nums.size();
    int temp;
    for(int step = length/2; step >= 1; step /=2){
        for (int i = step; i < length; ++i) {
            temp = nums[i];
            int j = i - step;
            while (j >=0 && nums[j] > temp)
            {
                nums[j+step] = nums[j];
                j -= step;
            }
            nums[j+step] = temp;
        }
    }
}

void shellSort_fourth(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

class solution{
public:
    void shellSort_fifth(vector<int>& nums)
    {

    }
private:
    void shellInsertionSort(vector<int>& nums, int step) {
        int length = nums.size();
        for (int i = step; i < length; ++i) {   // 用变量i当做步长
            int temp = nums[i]; // temp 哨兵，比对
            int j = i - step;
            while (j >= 0 && nums[j] > temp) {
                nums[j + step] = nums[j];
                j -= step;
            }
            nums[j + step] = temp;
        }
    }
};


// 2. 链表式
void ShellSort_N(SqList *L, int length) {
    int h = 1;
    while (h < length / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < length; ++i) {
            for (int j = i; j >= h && L->data[j] < L->data[j - h]; j -= h) {
                // swap [j] [j-h]
            }
        }
        h = h / 3;
    }
}


void ShellInsert_L(SqList *L, int dk) {
    // 增量dk， 暂存data[0], j<=0时插入位置找到
    int i, j;
    for (int i = dk + 1; i < L->length; ++i) {
        if (L->data[i] < L->data[i - dk]) {   // 希尔排序比较dk间距中，若前小则:__
            L->data[0] = L->data[i];    // L->data[0]==temp 暂存
            for (int j = i - dk; j > 0 && (L->data[0] < L->data[j]); j -= dk) {
                L->data[j + dk] = L->data[j];
            }
            L->data[j + dk] = L->data[0]; // insert
        }
    }
}

void ShellSort(SqList *L, int dlta[], int t) {
    for (int k = 0; k < t; ++k) {
        ShellInsert_L(L, dlta[k]);
    }
}



//
// Created by 陈至宇 on 2022/5/9.
//

#ifndef ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H
#define ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H

#endif //ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H
