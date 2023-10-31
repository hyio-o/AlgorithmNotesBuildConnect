//#include "../../0-初始化定义/2-链表定义.h"
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insert(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL || head->val >= newNode->val) {
        newNode->next = head;
        return newNode;
    }
    ListNode* cur = head;
    while (cur->next != NULL && cur->next->val < newNode->val) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    return head;
}

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* sorted = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        cur->next = NULL;
        sorted = insert(sorted, cur->val);
        cur = next;
    }
    return sorted;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "原始链表：";
    printList(head);

    head = insertionSortList(head);

    cout << "排序后的链表：";
    printList(head);

    return 0;
}





//
// Created by 陈至宇 on 2023/10/27.
//

#ifndef ALGORITHMNOTESBUILDING_6_插入排序_H
#define ALGORITHMNOTESBUILDING_6_插入排序_H

#endif //ALGORITHMNOTESBUILDING_6_插入排序_H
