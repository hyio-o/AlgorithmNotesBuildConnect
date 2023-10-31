#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
//#include "./1-栈定义.h"

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

// 双亲、孩子链表、双亲孩子、孩子兄弟
// 1. 双亲实现：--找双亲容易，找孩子难
// 定义数组结构存放树的结点，每个结点含两个域：
//数据域：存放结点本身数据信息。
//双亲域：指示本结点的双亲结点在数组中的位置。
/*这样的存储结构，根据结点parent指针很容易找到它的双亲结点，所用时间复杂度为O(1)，
 * 直到parent为-1时，找到了树的根结点，但是我们要知道结点的孩子是什么，对不起，请遍历整个结构才行。
 * 找双亲容易，找孩子难。*/
struct ParNode{
    Elemtype data;
    int parent; // 静态链表 指针域，双亲在数组下标
};
struct ParTree{
    ParNode nodes[MMAXN];
    int index, num; // 根节点位置、节点个数
};

// 2. 孩子链表--找孩子易，找双亲难
typedef struct CTNode{
    // 孩子节点 链表
    int child;
    struct CTNode* next;
}*ChildPtr;

typedef struct CTBox{
    // 表头结构
    Elemtype data;
    ChildPtr firstchild;
};

typedef struct CTree{
    CTBox nodes[MMAXN];
    int index, num; // 根节点位置、节点个数
}syruct;

// 3. 孩子兄弟表示法
/*任意一棵树，它的结点的第一个孩子如果存在就是唯一的，它的右兄弟如果存在也是唯一的。
 * 因此，我们用 二叉链表作树的存储结构，链表中每个结点的两个指针域分别指向第一个孩子结点和此结点的下一个兄弟结点*/
typedef struct CSNode{
    Elemtype data;
    struct CSNode *firstChild, *nextSibling;
}CSNode, *CSTree;


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
}*/


//
// Created by 陈至宇 on 2022/3/13.
//


