/* 54张牌-初始有序： 13张：S、H、C、D ;; 2张 J ：： S1 S2 ... J1 J2
 * 操作：将排的位置改变为指定位置：直接给出指定位置
 * 思路： 1。 定义两个数组 start[] end[] 操作前牌序 操作后牌序
 * */
#include <cstdio>
#include <cstdlib>

const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N + 1], end[N + 1], next[N + 1];    //  next存每个位置上牌操作后的位置

void shufflingMachine() {
    int K;
    scanf("%d", &K);
    for (int i = 1; i <= N; ++i) {
        start[i] = i;   // init 牌编号
    }
    for (int i = 1; i <= N; i++)
        next[i] = rand() % N; // TODO 需要生成不重复的随机数作为转移地址才行
    for (int step = 0; step < K; ++step) {
        for (int i = 1; i <= N; ++i) {
            end[next[i]] = start[i];    // 将第i位置牌编号存于next[i]
        }
    }
}


//
// Created by 陈至宇 on 2022/3/18.
//

#ifndef ALGORITHMNOTESBUILDING_A1042_SHUFFLING_MACHINE_H
#define ALGORITHMNOTESBUILDING_A1042_SHUFFLING_MACHINE_H

#endif //ALGORITHMNOTESBUILDING_A1042_SHUFFLING_MACHINE_H
