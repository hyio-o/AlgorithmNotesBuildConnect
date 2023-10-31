// WTL, 对应数组输出012，
// 三行各自最大的数： abc
#include <cstdio>

char S[3] = {'W', 'T', 'L'};

void WCB() {
    double ans = 1.0, temp, a;
    int index;
    for (int i = 0; i < 3; ++i) {
        temp = 0.0;
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &a);
            if (a > temp) {
                temp = a;
                index = j;
            }
        }
        ans *= temp;
        printf("%c", S[index]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
}

//
// Created by 陈至宇 on 2022/3/25.
//

#ifndef ALGORITHMNOTESBUILDING_A1011_WORLDCUPBETTING_H
#define ALGORITHMNOTESBUILDING_A1011_WORLDCUPBETTING_H

#endif //ALGORITHMNOTESBUILDING_A1011_WORLDCUPBETTING_H
