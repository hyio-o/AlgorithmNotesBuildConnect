#include "0-基本函数库.h"

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


//
// Created by 陈至宇 on 2022/5/10.
//

#ifndef ALGORITHMNOTESBUILDING_2_1_选择排序_H
#define ALGORITHMNOTESBUILDING_2_1_选择排序_H

#endif //ALGORITHMNOTESBUILDING_2_1_选择排序_H
