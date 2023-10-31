// 求最大公约数下求最小公倍数， lcm(a, b);
// 当gcd(a, b) = d, 有 lcm(a, b) = ab/d
#include "最大公约数.cpp"

int lcm(int a, int b) {
    int d = gcd_H(a, b);
    int val = a * b / d;
    return val;
}



//
// Created by 陈至宇 on 2022/2/26.
//

