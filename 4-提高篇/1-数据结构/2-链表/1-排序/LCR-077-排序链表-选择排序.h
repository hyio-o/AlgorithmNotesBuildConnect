#include "../../0-初始化定义/2-链表定义.h"


// 选择排序
/*根据你提供的代码片段，我可以看出你正在进行链表的选择排序操作，并将最小值节点Lindex插入到链表头部。下面是对你的代码进行逐步详细解释的过程：
Lindex = temp->next;：将temp节点的下一个节点赋值给Lindex，即Lindex指向最小值节点。
temp->next = temp->next->next;：将temp节点的next指针指向temp节点的下一个节点的下一个节点，即将temp节点的下一个节点从链表中删除。
Lindex->next = L->next;：将Lindex节点的next指针指向链表头节点L的下一个节点，即将Lindex节点插入到L的后面。
L->next = Lindex;：将链表头节点L的next指针指向Lindex节点，即将Lindex节点插入到链表头部，成为新的头节点。
selectSort_LinkList(L->next);：递归调用选择排序函数，对链表的剩余部分进行排序。
通过以上步骤，你可以将最小值节点Lindex插入到链表头部，并继续对链表进行选择排序操作。
如果你还有其他问题，请随时提问！*/
void selectSort_LinkList(LinkList &L){
    LinkList Lindex = L;
    LinkList temp = L;
    if(L->next != NULL){    // 本次（递归）链表非空
        while (Lindex->next != NULL){    // 找到最小/大值,并让指针下标给rear
            if(Lindex->next->data < temp->next->data){
                temp = Lindex;
            }
            Lindex = Lindex->next;
        }   // 本轮最小值找到，下标给rear了。
        Lindex = temp->next; // temp 马上升迁去固定位置，所以rear的后续交给front，
        // 将temp节点的下一个节点赋值给Lindex，即Lindex指向最小值节点

        // 那么rear的后续的后续
        temp->next = temp->next->next;  //
        Lindex->next = L->next;
        L->next = Lindex;
        selectSort_LinkList(L->next);
    }
    return;
}



//
// Created by 陈至宇 on 2023/10/26.
//

#ifndef ALGORITHMNOTESBUILDING_LCR_077_排序链表_选择排序_H
#define ALGORITHMNOTESBUILDING_LCR_077_排序链表_选择排序_H

#endif //ALGORITHMNOTESBUILDING_LCR_077_排序链表_选择排序_H
