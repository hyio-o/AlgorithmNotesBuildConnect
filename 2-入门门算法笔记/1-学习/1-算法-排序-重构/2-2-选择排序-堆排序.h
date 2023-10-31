#include "0-基本函数库.h"





// 1。交换 2。heapInsert 3。heapify

void heapSort(SqList **L) {

}

void heapInsert(SqList **L, int index) {
    while ((*L)->data[index] > (*L)->data[(index - 1) / 2]) // index比较index的父节点
    {
        //mySwap((*L)->data[index], (*L)->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

}

void heapify(SqList **L, int index, int heapSize) {
    int left = index * 2 + 1;   //左孩子
    while (left < heapSize) {  // 下方还有孩子
        // 俩孩子选最大
        int largest = (left + 1 < heapSize) && ((*L)->data[left + 1] > (*L)->data[left])
                      ? left + 1 : left;
        // 比较父亲和孩子选最大
        largest = (*L)->data[largest] > (*L)->data[index]
                  ? largest : index;
        if (largest == index)
            break;
        //mySwap(&(*L)->data[index], &(*L)->data[(index - 1) / 2]);
        index = largest;
        left = index * 2 + 1;
    }
}

void downAdjust(SqList **L, int s, int m) {
    // 小根堆
    int i = s, j = i * 2; // i预备调整点， 2i为左孩子
    while (j <= m) {   // 孩子存在
        // 右孩子存在&大于左孩子
        if (j + 1 <= m && (*L)->data[j + 1] > (*L)->data[j]) {
            j++;    // 存储右孩子下标
        }
        // 若孩子权值比欲将调整的结点更大
        if ((*L)->data[j] > (*L)->data[i]) {
            //mySwap(&(*L)->data[j], &(*L)->data[i]);
            i = j;
            j = i * 2;
        } else
            break;
    }
    return;
}


//
// Created by 陈至宇 on 2022/5/11.
//

#ifndef ALGORITHMNOTESBUILDING_2_2_选择排序_堆排序_H
#define ALGORITHMNOTESBUILDING_2_2_选择排序_堆排序_H

#endif //ALGORITHMNOTESBUILDING_2_2_选择排序_堆排序_H
