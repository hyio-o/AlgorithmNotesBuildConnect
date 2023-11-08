#include "../../0-初始化定义/2-链表定义.h"



void sortLink(LinkList &L){
//从小到大排序，本例子是换节点，直接更换节点的数据域也是可以的

    LinkList p=L;
    LinkList q=L;
    if(L->next!=NULL)	//链表非空
    {
        while(p->next!=NULL)
        {
            if(p->next->data < q->next->data)//查找最小节点进行排序
            {
                q=p;			//q指向最小节点的前一个节点
            }
            p=p->next;
        }
        p=q->next;				//p指向本轮最小节点
        q->next=q->next->next;	//将本轮最小节点从链表中剔除
        p->next=L->next;	//将原来头节点后的节点接到最小节点的后面
        L->next=p;			//将最小节点接到头节点后面
        sortLink(L->next);	//将最小节点作为头节点进行递归调用
    }
    return;//递归基
}

void sortLinkList(LinkList &L){
    // 创建一个指向头节点的指针p和一个指向当前最小节点前一个节点的指针q
    LinkList p = L;
    LinkList q = L;
    // 如果链表非空
    if (L->next != NULL) {
        // 遍历链表，直到找到最后一个节点
        while (p->next != NULL) {
            // 如果下一个节点的数据小于当前最小节点的数据
            if (p->next->data < q->next->data) {
                // 将q指向当前最小节点的前一个节点
                q = p;
            }
            // 移动指针p到下一个节点
            p = p->next;
        }
        // 将p指向当前最小节点
        p = q->next;
        // 将当前最小节点从链表中剔除
        q->next = q->next->next;
        // 将原来头节点后的节点接到最小节点的后面
        p->next = L->next;
        // 将最小节点接到头节点后面
        L->next = p;
        // 将最小节点作为头节点进行递归调用
        sortLink(L->next);
    }
    return; // 递归基
}



//
// Created by 陈至宇 on 2023/10/27.
//

#ifndef ALGORITHMNOTESBUILDING_5_选择排序_H
#define ALGORITHMNOTESBUILDING_5_选择排序_H

#endif //ALGORITHMNOTESBUILDING_5_选择排序_H
