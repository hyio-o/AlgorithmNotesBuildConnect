#include "大整数存储.h"
#include <cstdio>

bign add(bign a, bign b) {
    bign c;
    int carry = 0; // 进位
    for (int i = 0; i < a.len || i < b.len; ++i) {    // 以较长的为界限
        int temp = a.d[i] + b.d[i] + carry;    // 十以内，从低到高，进位也要加上
        c.d[c.len++] = temp % 10;
        carry = temp / 10;  //将其超出的十位再入
    }
    return c;
}

// 法一：够减直接减； 不够则令被减位高位减1 且 被减位+10再减
// 首先还是需要判定其长度和大小， 再用减法来计算
bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        if (a.d[i] < b.d[i]) {    //  当不够减
            a.d[i + 1]--; // 高位借一再给减
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i]; //最终答案出现
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;    //❓ 为何会有高位出现0000？
    }
}

// 法二， 先比较谁更大， 若被减数更大则直接减；若更小则添负号再用大的减小的
bign sub_N(bign a, bign b) {
    bign c;

}

// 使其拆分成个位乘以高位——高精度*低精度 ，再进行累加
bign multi(bign a, int b) {
    bign c;
    int carry = 0;   // 进位 -- 等效手算乘法
    for (int i = 0; i < a.len; ++i) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
        printf("::i=%d, temp=%d, carry=%d::\t", i, temp, carry);
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
}

//
// Created by 陈至宇 on 2022/3/2.
//

