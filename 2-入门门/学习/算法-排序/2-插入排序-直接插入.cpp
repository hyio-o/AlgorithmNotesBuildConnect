//
// Created by 陈至宇 on 2022/5/4.
//
#include "SortSources.cpp"

void InsertSort(SqList *L) {
    int i, j;
    for (int i = 2; i < L->length; ++i) {
        if (L->data[i] < L->data[i - 1]) {    // 后面那个i 若更小
            L->data[0] = L->data[i];    // watcher
            L->data[i] = L->data[i - 1];  // 左移
            for (int j = i - 2; L->data[0] < L->data[j]; j--) {
                L->data[j + 1] = L->data[j];
            }
            L->data[j + 1] = L->data[0];
        }
    }
    return;
}
