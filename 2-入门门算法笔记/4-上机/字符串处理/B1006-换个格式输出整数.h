// 输入数字，且在位数中设置要打印的符号次数 ;; 低位输入，高位输出

#include <cstdio>

void transOutPut() {
    int n, temp, len = -1, index = 0;
    char val[] = {'S', 'B', 'Q', 'W'};
    char output[60];
    scanf("%d", &n);
    temp = n % 10;
    n /= 10;
    for (int i = temp; i > 0; --i) {
        output[++len] = i + '0';
    }
    while (n != 0) {
        temp = n % 10;
        n /= 10;
        for (int i = 0; i < temp; ++i) {
            output[++len] = val[index];
        }
        ++index;
    }
    for (int i = len; i >= 0; --i) {
        printf("%c", output[i]);
    }
}


//
// Created by 陈至宇 on 2022/3/29.
//

#ifndef ALGORITHMNOTESBUILDING_B1006_换个格式输出整数_H
#define ALGORITHMNOTESBUILDING_B1006_换个格式输出整数_H

#endif //ALGORITHMNOTESBUILDING_B1006_换个格式输出整数_H
