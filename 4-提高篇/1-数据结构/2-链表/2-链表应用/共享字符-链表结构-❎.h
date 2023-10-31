#include <cstring>
#include <cstdio>

const int MMAXN = 100010;
struct NODE {
    char data;      //data
    int next;       //ptr
    bool flag;      //vive inOrder Linklist
} node[MMAXN];

void sharing_linklist() {
    for (int i = 0; i < MMAXN; ++i) {
        node[i].flag = false;
    }
    int s1, s2, n;      //s分别两条链表首地址
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;  //节点地址与后继节点地址
    char data;          //
    for (int i = 0; i < n; ++i) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for (int p = s1; p != -1; p = node[p].next) {
        // TODO 共享字符串， 链表设计何如？ 涉及字符串匹配
    }

}

//
// Created by 陈至宇 on 2022/3/8.
//

#ifndef ALGORITHMNOTESBUILDING_共享字符_链表结构_H
#define ALGORITHMNOTESBUILDING_共享字符_链表结构_H

#endif //ALGORITHMNOTESBUILDING_共享字符_链表结构_H
