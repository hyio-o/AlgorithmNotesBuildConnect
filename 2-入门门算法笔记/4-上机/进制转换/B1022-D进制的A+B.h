//输入两个非负十进制整数A和B ( ~ 2 3 0 - 1 ) ,输出A + B的D(1 <D~ IO) 进制数。
// 除留余数法
#include <cstdio>

void transformSys() {
    int A, B, C, temp, n;
    int val[33], len = 0;
    scanf("%d %d %d", &A, &B, &n);
    C = A + B;
    while (C != 0) {
        temp = C % n;
        C /= n;
        val[len++] = temp;
    }
    printf("\n\n");
    for (int i = len - 1; i >= 0; --i) {
        printf("%d ", val[i]);
    }
}


//
// Created by 陈至宇 on 2022/3/28.
//

#ifndef ALGORITHMNOTESBUILDING_B1022_D进制的A_B_H
#define ALGORITHMNOTESBUILDING_B1022_D进制的A_B_H

#endif //ALGORITHMNOTESBUILDING_B1022_D进制的A_B_H
