#include "../../0-初始化定义/2-链表定义.h"
#include <cstdio>

void Print_List(LinkList L, int val,int n) {//n为链表长度，val为开始遍历的节点
    int po;
    if (!L)return;
    else
    {
        ++po;
        if (po > val && po <= n) {
            if (L->next!=NULL) {
                std::cout << L->next->data << " ";
            }
        }
        Print_List(L->next, val,n);
    }


}





//
// Created by 陈至宇 on 2023/10/27.
//

#ifndef ALGORITHMNOTESBUILDING_2_查找单链表某个节点开始后的所有节点_H
#define ALGORITHMNOTESBUILDING_2_查找单链表某个节点开始后的所有节点_H

#endif //ALGORITHMNOTESBUILDING_2_查找单链表某个节点开始后的所有节点_H
