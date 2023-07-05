/*背包问题：： 选入背包物品重量不超过容量，让其和最大*/
#include <cstdio>

const int MMAXN = 30;
int n, V, maxVal = 0;
int w[MMAXN]{3, 5, 1, 2, 2}, c[MMAXN]{4, 5, 2, 1, 3};

void DFS(int index, int sumW, int sumC) {
    printf("::index=%d---%d==maxVal---%d==sumC::\n", index, maxVal, sumC);
    if (index == n) {     // 死胡同
        if (sumW <= V && sumC > maxVal) {
//            printf("::index=%d---%d==maxVal---%d==sumC::\n",index, maxVal, sumC);
            maxVal = sumC;
        }
        return;
    }
    DFS(index + 1, sumW, sumC);       // 不选index
    DFS(index + 1, sumW + w[index], sumC + c[index]); //选index
}

void index_DFS() {
    n = 5, V = 8;


    DFS(0, 0, 0);
    printf("\n\n%d\n", maxVal);
}

//
// Created by 陈至宇 on 2022/3/12.
//

#ifndef ALGORITHMNOTESBUILDING_3_1_DFS_H
#define ALGORITHMNOTESBUILDING_3_1_DFS_H

#endif //ALGORITHMNOTESBUILDING_3_1_DFS_H
