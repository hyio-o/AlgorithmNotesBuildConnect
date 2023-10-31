#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findMax(ListNode* head) {
    if (head == NULL) {
        return INT_MIN;
    }
    int maxVal = findMax(head->next);
    return max(maxVal, head->val);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "链表中的最大值为：" << findMax(head) << endl;

    return 0;
}



//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_8_递归求链表最大值_H
#define ALGORITHMNOTESBUILDING_8_递归求链表最大值_H

#endif //ALGORITHMNOTESBUILDING_8_递归求链表最大值_H
