/*思路： 作为长整型存储： 字符数组：：A， B */
// 简单的字符串遍历程序，
// 时间复杂度： O(n), 要遍历一次字符数组， 每条一次
#include <cstdio>

#define maxn 21

void partOFApB() {
    char A[maxn], B[maxn];
    int Pa = 0, Pb = 0, Da, Db, sumAB;
    char temp;
    scanf("%s%d%s%d", A, &Da, B, &Db);
    //printf("\n\n::%s:: ::%d:: ::%s:: ::%d::\n", A, Da, B, Db);
    for (int i = 0, t = 0; A[i] != '\0' || B[t] != '\0'; ++i, ++t) {
        if (Da == (A[i] - '0')) {
            Pa *= 10;
            Pa += Da;
        }
        if (Db == (B[i] - '0')) {
            Pb *= 10;
            Pb += Db;
        }
    }
    sumAB = Pa + Pb;
    printf("%d", sumAB);


}

// 选择用long long
void partOFApB_N() {

}
//
// Created by 陈至宇 on 2022/3/15.
//

#ifndef ALGORITHMNOTESBUILDING_B1016_部分A_B_H
#define ALGORITHMNOTESBUILDING_B1016_部分A_B_H

#endif //ALGORITHMNOTESBUILDING_B1016_部分A_B_H
