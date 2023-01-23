#include <cstdio>
#include <cstdlib>
#include <time.h>
/*思路： 应该视为将事件触发赋予权值， 并根据其逻辑关系来改进算法*/
// 两个人的交锋： 一共八种状态，如果不用全部枚举标识的话：
// 双方分别出什么手势胜算最大：： 投票法， ｜｜ 主要是给猜拳的手势加权值：布为0， 剪刀-1， 锤子1
// B对C即 0：1
// B对J即 0：-1
// J对B即 -1：0
/* 可以不用如此编码的麻烦， 可以看出一个线性关系 B C J ：0 1 2 ；； 再判断二者的位置
 * k1胜k2条件： (k1+1)%3=k2 || 在其前面相克后面的
 * k1输k2条件： (k2+1)%3=k1
 * 平局条件： k1==k2*/
/* 胜负： 1。 输， 2。赢， 3。 平局*/
/*step1：首先将数组输入进去，作为两个比较级别来判定*/

void createJBC(int *A, int *B, int &len_A, int &len_B) {
    //srand((unsigned ) time(NULL));
    for (int i = 0; i < 100; ++i) {
        A[i] = rand() % 3;
        len_A++;
        B[i] = rand() % 3;
        len_B++;
        // printf("--%d::%d--\t", A[i], B[i]);
    }
}

void compareJBC(int *A, int *B, int len_A, int len_B, bool *win_A, bool *win_B) {
    /*for (int i = 0, t=0; i<len_A, t<len_B; ++i, ++t) {
        printf("%d::%d\t", A[i], B[t]);
    }*/
    int countWin_A = 0, countWin_B = 0;
    for (int i = 0; i < 110; ++i) {
        win_A[i] = false;
        win_B[i] = false;
    }
    for (int i = 0; i < len_A; ++i) {
        if ((A[i] + 1) % 3 == B[i]) {
            win_A[i] = true;
            countWin_A++;
        }    // (k1+1)%3=k2
        else if ((B[i] + 1) % 3 == A[i]) {
            win_B[i] = true;
            countWin_B++;
        } else
            continue;
    }
    printf("winA: %d\nwinB: %d", countWin_A, countWin_B);
}



//
// Created by 陈至宇 on 2022/3/17.
//

#ifndef ALGORITHMNOTESBUILDING_B1018_锤子剪刀布_H
#define ALGORITHMNOTESBUILDING_B1018_锤子剪刀布_H

#endif //ALGORITHMNOTESBUILDING_B1018_锤子剪刀布_H
