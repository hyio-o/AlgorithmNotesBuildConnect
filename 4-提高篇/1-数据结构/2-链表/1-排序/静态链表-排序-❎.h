#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
struct StaLinkNode {
    int address, data, next;
    bool flag;  // 结点于链表有效
} StaLinkNodes[MAXN];

bool cmp(StaLinkNode x, StaLinkNode y) {
    if (!x.flag || !y.flag) {    //若有一个为false， 即不在链表中
        return x.flag > y.flag; //TODO 只要x和y有一个无效，就把它放到后面去
    } else
        return x.data < y.data; // 不是bool结构吗？返回 data可是int结构？？？
}

void StaSort() {
    for (int i = 0; i < MAXN; ++i) {
        StaLinkNodes[i].flag = false;
    }
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; ++i) {
        scanf("%05d %d %05d", &address, &StaLinkNodes[address].data, &StaLinkNodes[address].next);
        StaLinkNodes[address].address = address;
    }
}




//
// Created by 陈至宇 on 2022/3/11.
//

#ifndef ALGORITHMNOTESBUILDING_静态链表_排序_H
#define ALGORITHMNOTESBUILDING_静态链表_排序_H

#endif //ALGORITHMNOTESBUILDING_静态链表_排序_H
