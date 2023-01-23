//1。 time.h --> clock()
//2. CLK_TCK 常数，记录机器始终
/*思路：调用函数f之前先调用clock(), 以获得时钟打点数C1； 执行f之后调用clock（）获得打点数C2
 * (C2-C1)/CLK_TCK 得到以s为单位的运行时间，
 * 设 CLK_TCK = 100
 * */
#include <cstdio>

void timeMachine() {
    int c1 = 123, c2 = 4577973;
    //scanf("%d%d", &c1, &c2);
    int ans = c2 - c1;
    if (ans % 100 >= 50)
        ans = ans / 100 + 1;
    else
        ans /= 100;
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return;
}

//
// Created by 陈至宇 on 2022/3/16.
//

#ifndef ALGORITHMNOTESBUILDING_B1026_程序运行时间_H
#define ALGORITHMNOTESBUILDING_B1026_程序运行时间_H

#endif //ALGORITHMNOTESBUILDING_B1026_程序运行时间_H
