// 辗转相除法⭐️ gcd(a, b) = gcd(b, a%b)
#include <cstdio>

// 递归
int gcd_H(int a, int b) {
    if (b == 0) return a;  // 递归边界： gcd(a, 0) = a
    else return gcd_H(b, a % b);
}

int gcd_H2(int a, int b) {
    if (a < b) {    // 交换a b
        int temp = a;
        a = b;
        b = temp;
    }
    return (b == 0) ? a : gcd_H2(b, a % b);
}

// 非递归
int gcd_N(int a, int b) {
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    while (b > 0) {    // 不断用其两者中更小的那个来求余，且直到有一个求成0的时候，最大公约数就出现了
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//
// Created by 陈至宇 on 2022/2/26.
//

