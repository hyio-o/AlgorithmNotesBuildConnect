#include <cstdio>
/*思想：一组数组中是否存在两个数相加， 使得其和为M；；*/
// 法一：穷举
void towPointers_H(int *A, int length, int M) {
    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            if (A[i] + A[j] == M)
                printf("%d %d\n", A[i], A[j]);
        }
    }
}

// 法二：

//
// Created by 陈至宇 on 2022/2/27.
//

