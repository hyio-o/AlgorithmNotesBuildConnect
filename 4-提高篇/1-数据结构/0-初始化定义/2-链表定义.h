#include <cstdlib>

typedef int element;    //定义元素

//定义结点类型
typedef struct Node{
    element val;
    struct Node *next;
}Node, *LinkedList; //Node： 结点的类型。*LinkedList指向结点的 指针类型

//单链表初始化
LinkedList initList(){
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    if(!L)
        exit(0);
    L->next = NULL;
}   //需要养成创建是否失败的认证的习惯；（一旦失败后果不堪设想）

// 创建单链表-头插
LinkedList createHeadList(){

}

// 创建单链表-尾插


//
// Created by 陈至宇 on 2023/5/15.
//

#ifndef ALGORITHMNOTESBUILDING_2_链表定义_H
#define ALGORITHMNOTESBUILDING_2_链表定义_H

#endif //ALGORITHMNOTESBUILDING_2_链表定义_H
