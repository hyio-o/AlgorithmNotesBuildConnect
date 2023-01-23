#include <cstdio>
//
// Created by 陈至宇 on 2022/2/22.
//

// 1。找最值 2。放边边 3。缩短距离
void selectSort(int *A, int n)  // 递减序列
{
    for (int i = 1; i < n; ++i) {
        int k = i;  // 标的最值
        for (int j = i; j < n; ++j) {
            if (A[j] > A[i])
                k = j;
        }
        // exchange(k, i);
        // 此i自增而自然缩短边距
    }
}
