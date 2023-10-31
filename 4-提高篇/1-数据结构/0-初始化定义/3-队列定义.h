#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

#include "1-栈定义.h"
#include "2-链表定义.h"
#include "4-二叉树定义.h"

// 定义队列
typedef struct SeQueue{
    BiTNode *data[MMAXN]{};
    int front, rear;
    SeQueue(){
        front = 0, rear=0;
        for (int i = 0; i < MMAXN; ++i) {
            data[i] = nullptr;
        }
    }
}SeQueue;

bool isEmptySe(SeQueue Se){
    if(Se.front == Se.rear) return true;
    else return false;
}
bool isFullSe(SeQueue Se){
    if((Se.rear+1)%MMAXN == Se.front)    return true;
    else return false;
}

// EnQueue
void enQueue(SeQueue &Se, BiTNode *T){
    if(!isFullSe(Se)){
        Se.data[Se.rear] = T;
        Se.rear = (Se.rear+1)%MMAXN;
    }
}
// DeQueue
void deQueue(SeQueue &Se, BiTNode *&T){
    if(!isEmptySe(Se)){
        T = Se.data[Se.front];
        Se.front = (Se.front+1)%MMAXN;
    }
}
// count queue
int countQueue(SeQueue Se){
    return (Se.rear-Se.front+MMAXN)%MMAXN;
}




//
// Created by 陈至宇 on 2023/5/15.
//

#ifndef ALGORITHMNOTESBUILDING_3_队列定义_H
#define ALGORITHMNOTESBUILDING_3_队列定义_H

#endif //ALGORITHMNOTESBUILDING_3_队列定义_H
