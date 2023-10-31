#include "../../0-初始化定义/2-链表定义.h"

class solution{
public:
    // 双指针， indexr->next = pre;  pre = indexr; indexr++;
    LinkList reverseList_second(LinkList head){
        LinkList prev = NULL, tempFORnext;
        LinkList indexr = head;
        while(indexr != NULL){
            tempFORnext= indexr->next;    // temp临时节点保存当下indexr的下一节点，用于后移 10<->13
            indexr->next = prev;    // 将当前节点指向他前面的结点；   重点
            prev = indexr;  // 前指针后移                         重点
            indexr= tempFORnext;   // 当前指针后移
        }

    }
    // 双指针
    LinkList reverseList_first(LinkList head){
        ListNode *temp; //
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur){
            temp = cur->next;   // cur 改变前的处置，
            cur->next = pre;    //
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    // 递归
    LinkList reverseList_rec(LinkList head){

    }

    /*首先检查输入的链表头节点 head 是否为空或者只有一个节点。如果是，则直接返回 head，因为这种情况下链表已经是反转的了。
    如果链表有多个节点，定义两个指针变量 rlink_head 和 temp。其中，rlink_head 用于存储反转后的链表头节点，
     而 temp 用于临时存储当前节点的下一个节点。
    调用递归函数 reverseList(head->next)，将当前节点的下一个节点作为参数传入。这个递归调用的目的是反转从第二个节点开始的子链表。
    将递归调用的结果赋值给 rlink_head，即反转后的链表头节点。
    将当前节点的下一个节点赋值给 temp，以便后续操作。
将当前节点的下一个节点的 next 指针指向当前节点，即将当前节点插入到反转后的子链表中。
将当前节点的 next 指针设置为 NULL，表示当前节点是反转后链表的最后一个节点。
返回反转后的链表头节点 rlink_head。*/
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *rlink_head, *temp;
        rlink_head = reverseList(head->next);   // 1 -> 2 -> 3 -> 4 -> 5
        temp = head->next;  //  2->
        temp->next = head;  //  1->
        head->next = NULL;  //
        return rlink_head;
    }
    /*假设我们有一个链表 1 -> 2 -> 3 -> 4 -> 5，我们希望将其反转为 5 -> 4 -> 3 -> 2 -> 1。
首先，我们调用 reverseList(head)，传入的参数是链表头节点 1。因为链表有多个节点，所以我们进入函数内部。
在函数内部，我们定义了两个指针变量 rlink_head 和 temp。rlink_head 用于存储反转后的链表头节点，
     而 temp 用于临时存储当前节点的下一个节点。
接下来，我们调用递归函数 reverseList(head->next)，将当前节点的下一个节点作为参数传入。
     这个递归调用的目的是反转从第二个节点开始的子链表。
假设递归调用返回的结果为反转后的子链表头节点 5。我们将这个结果赋值给 rlink_head，即反转后的链表头节点。
然后，我们将当前节点的下一个节点赋值给 temp，即 2。
接下来，我们将当前节点的下一个节点的 next 指针指向当前节点，即将当前节点插入到反转后的子链表中。
     此时，链表变为 2 -> 1（原来的链表头节点）-> 5（反转后的子链表头节点）。
最后，我们将当前节点的 next 指针设置为 NULL，表示当前节点是反转后链表的最后一个节点。此时，链表变为 2 -> 1 -> 5。
回到最初的调用 reverseList(head)，我们将反转后的子链表头节点 5 返回给上一层调用。这样，整个链表就被逐个反转了。
     最终得到的链表为 5 -> 4 -> 3 -> 2 -> 1。*/
    /*ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;*/

};



//
// Created by 陈至宇 on 2023/10/27.
//

#ifndef ALGORITHMNOTESBUILDING_3_链表反转_H
#define ALGORITHMNOTESBUILDING_3_链表反转_H

#endif //ALGORITHMNOTESBUILDING_3_链表反转_H
