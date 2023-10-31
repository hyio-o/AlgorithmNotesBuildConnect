// 对任意自然数n， 若为偶数， 砍掉一半； 若为奇数， 将其(3n+1)砍掉一半
// ==>得到n=1
// 偶数判别： n%2 == 0 ；； 奇数判别： n%2 == 1
//
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

void callatzSuspect() {
    printf("\nPlease enter a num as natural num.\n: ");
    int n = 0, count = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 2 == 1)
            n = (3 * n + 1) / 2;
        count++;
    }
    printf("\n::%d:: -- step inOrder needed", count);
}

int callatzSus(unsigned int n)
{
    unsigned int temp = n;
    int sig = -1;
    int count_num = 0;
    int une_num = 0, e_num = 0;
    while ((n!=1) && (n < 1000) && count_num <= 10000)
    {
        sig = temp % 2; // sig == 奇数/偶数
        if(sig) // 奇数
        {
            temp = (temp*3 + 1)/2;
            une_num++;
        }
        else
        {
            temp = temp / 2;
            e_num++;
        }
        count_num++;
    }
    printf("%d == uneven num, %d == even num\n", une_num, e_num);

    return count_num-1;
}

//
// Created by 陈至宇 on 2022/3/15.
//

#ifndef ALGORITHMNOTESBUILDING_B_1001_3N_1卡拉兹猜想_H
#define ALGORITHMNOTESBUILDING_B_1001_3N_1卡拉兹猜想_H

#endif //ALGORITHMNOTESBUILDING_B_1001_3N_1卡拉兹猜想_H
