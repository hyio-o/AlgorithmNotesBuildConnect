#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

// 1清空 2size 3empty 4push 5pop 6top
/*
 * 1 数组栈 == 顺序栈
 * 2 链栈
 * */

#define MAXSIZE 210
typedef char ELemType;
typedef struct DMSeqStack {
    ELemType data[MAXSIZE];
    int TOP;    // 表示数组地址位置；；
    DMSeqStack() {
        // memset:: void *memset(void *str, int c, size_t n)
        // :str -- 指向要填充的内存块。
        // c -- 要被设置的值。该值以 int 形式传 递，但是函数在填充内存块时是使用该值的无符号字符形式
        // n -- 要被设置为该值的字符数。   MAXSIZE == sizeof(data) ???❓
        memset(data, 0, sizeof(data));
        TOP = -1;
    }
};

void initStack(DMSeqStack S) {
    printf("Stack initiating.. \n%d == TOP", S.TOP);
}

bool PushSqStack(DMSeqStack &Sq, ELemType el) {
    if (Sq.TOP == MAXSIZE - 1)
        return false;
    Sq.data[++Sq.TOP] = el;
    return true;
}

ELemType PopSqStack(DMSeqStack &Sq) {
    if (Sq.TOP == -1)
        return '\0';
    else {
        return Sq.data[Sq.TOP--];
    }
}

ELemType TopSqStack(DMSeqStack Sq) {
    if (Sq.TOP == -1)
        return '\0';
    else
        return Sq.data[Sq.TOP];
}

bool isEmptySq(DMSeqStack Sq) {
    if (Sq.TOP <= 0)
        return true;
    else
        return false;
}


/* 链栈定义 */



//
// Created by 陈至宇 on 2022/3/6.
//


//
// Created by 陈至宇 on 2023/5/15.
//

#ifndef ALGORITHMNOTESBUILDING_1_栈定义_H
#define ALGORITHMNOTESBUILDING_1_栈定义_H

#endif //ALGORITHMNOTESBUILDING_1_栈定义_H
