/*
//
// Created by 陈至宇 on 2022/2/22.
//

#include <cstdio>
// 除留余数法
void BaseConvertABD(int A, int B, int D)
{
    scanf("%d%d", &A, &B);
    long int sum = A+B;
    int ans[31], num = 0;
    do {
        ans[num++] = sum%D;
        sum /= D;
    } while (sum != 0);

}*/
