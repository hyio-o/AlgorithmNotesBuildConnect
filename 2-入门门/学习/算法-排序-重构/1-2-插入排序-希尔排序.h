#include "0-基本函数库.h"

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


void ShellInsert(SqList *L, int dk) {
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
        ShellInsert(L, dlta[k]);
    }
}


//
// Created by 陈至宇 on 2022/5/9.
//

#ifndef ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H
#define ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H

#endif //ALGORITHMNOTESBUILDING_1_2_插入排序_希尔排序_H
