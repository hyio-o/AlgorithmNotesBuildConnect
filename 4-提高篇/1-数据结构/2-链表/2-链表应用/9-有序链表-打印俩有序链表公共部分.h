// 谁小谁移动，相等的打印；打印之后共同移动

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printCommon(ListNode *head1, ListNode *head2) {
    if (!head1 || !head2) return;

    ListNode *p1 = head1, *p2 = head2;
    while (p1 && p2 && p1->val == p2->val) {
        cout << p1->val << " ";
        p1 = p1->next;
        p2 = p2->next;
    }
}

int main() {
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(5);
    head2->next->next->next = new ListNode(6);

    printCommon(head1, head2);

    return 0;
}


//
// Created by 陈至宇 on 2022/5/16.
//

#ifndef ALGORITHMNOTESBUILDING_有序链表_打印俩有序链表公共部分_H
#define ALGORITHMNOTESBUILDING_有序链表_打印俩有序链表公共部分_H

#endif //ALGORITHMNOTESBUILDING_有序链表_打印俩有序链表公共部分_H
