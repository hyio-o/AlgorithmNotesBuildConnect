#include "../../0-初始化定义/2-链表定义.h"

class solution{
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode; // 创建一个虚拟头节点
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = curr;
            prev->next = nextNode;

            prev = curr;
            curr = curr->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(!head || !head->next){
                return head;
            }
            // head rear swapPairs(rear->next)
            ListNode *rear = head->next;
            head->next = swapPairs(rear->next);
            rear->next = head;
            return rear;
        }
    };
};

//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_10_两两交换链表中节点_H
#define ALGORITHMNOTESBUILDING_10_两两交换链表中节点_H

#endif //ALGORITHMNOTESBUILDING_10_两两交换链表中节点_H
