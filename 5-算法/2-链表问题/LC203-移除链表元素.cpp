#include "../2-链表定义.h"
// 需要 手动回收 free(node) 节点；
// 3种方法
//1. 使用虚拟头结点
//2. 直接原来的节点
//3. 递归方法 （ 问题是如何释放掉空间 )
/*1. 虚拟 ： 所有节点都是统一方式 赋予 index 结点指针， 再删除*/
class solution_virtual{
public:
    linkList *removeELem(linkList *head, Elemtype target){ //删除结点
        linkList *temp = new linkList(0);  //设置虚拟头仍然需要分配实体空间
        temp->next = head; // 使虚拟头成为"头"
        linkList *index = temp;
        while (index != NULL)
        {
            if(index->val == target){   // 删除结点

            }
            index = index->next;
        }
    }
};

/*2. 原来的：实结点；
 * 需要区别对待 头结点head， 只需要往后移就能实现删除*/


/*
 * */

//
// Created by 陈至宇 on 2023/2/10.
//
