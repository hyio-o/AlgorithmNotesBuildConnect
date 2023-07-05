// 回文串+进制转换
// 1. 先进制转换进数组里面，
// 2。再判定是否为回文串
#include <cstdio>

void GPNum() {
    int temp, X, len = -1, n; // n进制方法
    int val[33];
    scanf("%d %d", &X, &n);
    while (X != 0) {
        temp = X % n;
        X /= n;
        val[++len] = temp;
    }

    for (int i = 0, t = len; i <= len / 2; ++i, --t) {
        if (val[i] == val[t])
            continue;
        else
            printf("No");
        //printf("%d ", val[i]);
    }
    for (int i = 0; i < len; ++i) {
        printf("%d ", val[i]);
    }
}


//
// Created by 陈至宇 on 2022/3/28.
//

#ifndef ALGORITHMNOTESBUILDING_A1019_GENERALPALINDROMICNUM_H
#define ALGORITHMNOTESBUILDING_A1019_GENERALPALINDROMICNUM_H

#endif //ALGORITHMNOTESBUILDING_A1019_GENERALPALINDROMICNUM_H
