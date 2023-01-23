
// 口喊数两个H1， H2； 比划数两个B1，B2； 当比划数==口喊数之和：B1==H1+H2 或 B2==H1+H2 得到者胜利
// 同赢或者同输继续下一轮直到唯一的赢家出现；
// 记录分别喝了多少酒
/*思路： 带上随机数来喊；*/
#include <cstdlib>
#include <cstdio>
#include <time.h>

void KikSlip() {
    // 重新分配种子
    //srand((unsigned ) time(NULL));
    int H1, H2, B1, B2, A1 = 0, A2 = 0;
    bool win = false;
    while (!win) {
        H1 = rand() % 6;
        H2 = rand() % 6;
        B1 = rand() % 10;
        B2 = rand() % 10;
        if (B1 == H1 + H2 && B2 == H1 + H2)
            continue;
        else if (B1 == H1 + H2)
            A2++;
        else if (B2 == H1 + H2)
            A1++;
        break;
    }
}


//
// Created by 陈至宇 on 2022/3/16.
//

#ifndef ALGORITHMNOTESBUILDING_B1046_划拳_H
#define ALGORITHMNOTESBUILDING_B1046_划拳_H

#endif //ALGORITHMNOTESBUILDING_B1046_划拳_H
