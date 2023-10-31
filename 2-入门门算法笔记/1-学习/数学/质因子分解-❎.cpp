#include <cstdio>
#include <cmath>

// 将一个正整数n分解成多个质数的乘积
// 1. 枚举1~sqrt(n)所有质因子p， 判断p是否n的因子
struct factor {
    int x, cnt;
} fac[10];

void enumPrime(int *prime, int n) {
    int num = 0;
    int sqr = sqrt(n);
    for (int i = 0; i < sqr; ++i)
        if (n % prime[i] == 0) { // 若此为n的因子
            fac[num].x = prime[i];  //  记录因子
            fac[num].cnt = 0;
            while (n % prime[i] == 0) {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
}


//
// Created by 陈至宇 on 2022/3/1.
//

