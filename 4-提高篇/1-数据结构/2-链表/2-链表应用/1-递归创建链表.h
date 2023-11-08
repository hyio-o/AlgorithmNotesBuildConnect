#include "../../0-初始化定义/2-链表定义.h"

// 创建链表 递归 尾插

void createLinkList(LinkList &L, int n){
    if(n == 0) return;
    else{
        L = new ListNode;
        L->next = NULL;
        scanf("%d", &L->data);
        createLinkList(L->next, n-1);
    }
}

// 统计链表节点
int countLinkList(LinkList &L){
    if(L == NULL) return 0;
    else{
        return countLinkList(L->next) + 1;
    }
}

// 打印链表
void printLinkList_forward(LinkList L){
    if(L == NULL) return;
    else{
        std::cout << L->data << std::endl;
        printLinkList_forward(L->next);
    }
}
void printLinkList_reverse(LinkList L){
    if(L == NULL) return;
    else{
        printLinkList_reverse(L->next);
        std::cout << L->data << std::endl;
    }
}




//
// Created by 陈至宇 on 2023/10/24.
//

#ifndef ALGORITHMNOTESBUILDING_1_创建链表_H
#define ALGORITHMNOTESBUILDING_1_创建链表_H

#endif //ALGORITHMNOTESBUILDING_1_创建链表_H
