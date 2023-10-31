#include <cstdio>

// 快排枢轴， 交换排序✅ ｜｜ 选择排序 进阶
// 划分左右区间
int Partition(int *A, int left, int right) {
    int temp = A[left];     // 作为枢轴
    while (left < right) {     // 只要左右不相遇
        // 只要不相遇 且 right方比temp大 则反复左移;; 反之亦然 ；；；当不大时交换 left和right的位置， 当左右相遇则把temp送给left
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] < temp) left--;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int *A, int left, int right) {
    if (left < right) {
        // 类先根遍历 ❓
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}
//
// Created by 陈至宇 on 2022/2/27.
//

