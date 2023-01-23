/*如何使得移动次数尽量少：
 * len = 长度； M为移动个数*/
// 如果它只要求输出：那么可以不用移动而直接输出：：输出规则为 move = len%M，且为倒数len-move开始输出到末位，
// 再从0地址开始输出到move前一位
// ❌第一次错误： 误以为将 输出规则为 move = len%M；； 但是实际上可能 M>len; 因此
//  move = M%len
#include <cstdio>

#define maxn 110

void loopMoveSlink() {
    int len = 0, M = 0;
    int mySlink[maxn];
    scanf("%d%d", &len, &M);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &mySlink[i]);
    }
    printf("%d\n\n", M % len);
    if ((M % len) != 0) {
        for (int i = len - M % len; i < len; ++i)
            printf("-:%d:- ", mySlink[i]);
        for (int i = 0; i < len - M % len; ++i) {
            printf("--%d-- ", mySlink[i]);
        }
    } else
        for (int i = 0; i < len; ++i)
            printf("::%d:: ", mySlink[i]);
    // 若是行末不需要多余空格，则需要对for循环进行条件判断空格输出
}


//
// Created by 陈至宇 on 2022/3/17.
//

#ifndef ALGORITHMNOTESBUILDING_B1008_数组循环右移_H
#define ALGORITHMNOTESBUILDING_B1008_数组循环右移_H

#endif //ALGORITHMNOTESBUILDING_B1008_数组循环右移_H
