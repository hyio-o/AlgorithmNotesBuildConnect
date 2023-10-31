#include "0-基本函数库.h"

using namespace std;
// 2.1 原地归并
class mergeSortSolution{
public:

    vector<int> mergeSort(vector<int> &nums_old)
    {
//        nums_new.resize(nums_old.size());
        sort(nums_old, 0, nums_old.size()-1);
        return nums_old;
    }

    void merge(vector<int> &nums_old, int lChild, int mid, int rChild)
    {   // 将nums[lChild, mid] 和 nums[mid, rChild] 归并
        int index_L = lChild, index_R = mid+1;

        for (int i = lChild; i <= rChild; ++i) {    // 将nums[lChild,rChild]复制一份到 nums_new[]
            nums_new[i] = (nums_old[i]);
        }
        for (int i = lChild; i <= rChild; ++i) {
            if(index_L > mid){
                nums_old[i] = nums_new[index_R];
                index_R++;
            }
            else if(index_R > rChild){
                nums_old[i] = nums_new[index_L];
                index_L++;
            }
            else if(nums_new[index_R] < nums_new[index_L]){
                nums_old[i] = nums_new[index_R];
                index_R++;
            }
            else{
                nums_old[i] = nums_new[index_L];
                index_L++;
            }
        }
        return;
    }

private:
    vector<int> nums_new;
    void sort(vector<int> &nums, int lChild, int rChild){
        if(lChild >= rChild)    return;
        int mid = lChild + (rChild - lChild)/2;  // （lChild + rChild）/2 防止溢出办法
        sort(nums, lChild, mid);
        sort(nums, mid+1, rChild);
        merge(nums, lChild, mid, rChild);
    }

};


//
// Created by 陈至宇 on 2023/9/16.
//

#ifndef ALGORITHMNOTESBUILDING_3_归并排序_H
#define ALGORITHMNOTESBUILDING_3_归并排序_H

#endif //ALGORITHMNOTESBUILDING_3_归并排序_H
