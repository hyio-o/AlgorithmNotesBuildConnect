#include "素数判断.cpp"
#include <cstdio>

void getPrime(int *A) {
    const unsigned int MAXN = 65535;
    for (int val = 1, t = 0; val < MAXN; ++val) {
        if (isPrime(val))
            A[t++] = val;
    }

}



//
// Created by 陈至宇 on 2022/2/27.
//

