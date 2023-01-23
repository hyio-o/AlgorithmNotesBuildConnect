#include <cstdio>
#include <unistd.h>

void divide() {
    const int MAXN = 101;
    int prime[MAXN], pNum = 0;
    bool p[MAXN] = {0};
    for (int i = 2; i < MAXN; ++i) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = 2 * i; j < MAXN; j += i) {
                p[j] = false;
                printf("\t:: i=%d   j=%d ::\t", i, j);
            }
        }
        printf("\n");
        sleep(1);
    }
}


//
// Created by 陈至宇 on 2022/3/1.
//

