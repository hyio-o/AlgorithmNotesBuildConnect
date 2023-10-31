// #include "2-入门门算法笔记/1-学习/1-算法-排序-重构/1-2-插入排序-希尔排序.h"
#include "2-入门门算法笔记/1-学习/1-算法-排序-重构/3-归并排序.h"

int main() {
    printf("hello, world!\n");
    // heapSortSolution myHeapSort;
    // shellSortSolution myShellSort;
    mergeSortSolution myMergeSort;
    vector<int> mynums;
    mynums = myMergeSort.mergeSort(nums_A);

    for (int i = 0; i < mynums.size(); ++i) {
        printf(" [%d] - %d \t", mynums[i], i);
    }
    printf("\nhere you are\n");

    return 0;
}
