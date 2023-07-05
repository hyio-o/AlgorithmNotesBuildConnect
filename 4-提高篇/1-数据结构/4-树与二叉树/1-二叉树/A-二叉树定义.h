#ifndef ALGORITHMNOTESBUILDING_二叉树定义_H
#define ALGORITHMNOTESBUILDING_二叉树定义_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <string>

#define MMAXN 1000

using namespace std;

typedef int Elemtype;

Elemtype pre_OrderL[] = {1, 2, 4, 3, 5, 7, 6};
Elemtype in_OrderL[] = {2, 4, 1, 5, 7, 3, 6};


// restruct BiTNode
typedef struct BiTNode {
    Elemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


// stack define
//
typedef struct SqStack {
    BiTNode *data[MMAXN];
    int top;

    SqStack() {
        top = -1;
    }
} SqStack;

void initStack(SqStack Sq) {
    Sq.top = -1;
}

bool Push(SqStack &Sq, BiTNode *el) {
    if (Sq.top == MMAXN - 1)
        return false;
    Sq.data[++Sq.top] = el;
    return true;
}

bool Pop(SqStack &Sq, BiTNode *&el) {
    if (Sq.top == -1)
        return false;
    el = Sq.data[Sq.top--];
    return true;
}

bool isEmptySq(SqStack Sq) {
    if (Sq.top == -1) return true;
    return false;
}

bool getTop(SqStack Sq, BiTNode *&el) {
    if (Sq.top == -1) return false;
    el = Sq.data[Sq.top];
    return true;
}

BiTree lastEle(SqStack Sq) {
    return Sq.data[0];
}

int count_n = 0;

void visit(BiTNode *T) {
    if (T) {
        printf(":%d  ", T->data);
        //if(T->lchild) printf("    T.lchild==%d    ", T->lchild->data);
        //if(T->rchild) printf("    T.rchild==%d    ", T->rchild->data);
    }
    ++count_n;
    //if(count_n%3 == 0)    printf("\n");
}

/*
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


*/
//
// Created by 陈至宇 on 2022/3/13.
//


#endif //ALGORITHMNOTESBUILDING_二叉树定义_H

