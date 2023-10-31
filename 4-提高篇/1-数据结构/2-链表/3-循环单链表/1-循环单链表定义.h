#include <iostream>
using namespace std;

/*
 * 循环单链表相比普通单链表，在以下操作上更为方便：
循环遍历：循环单链表可以方便地从头节点开始循环遍历整个链表，而普通单链表需要进行特殊处理或者遍历到尾节点才能结束遍历。
插入和删除操作：在循环单链表中，插入和删除节点时，可以避免特殊处理头节点和尾节点的链接关系，因为它们之间已经形成了一个闭环。而在普通单链表中，需要额外处理头节点和尾节点的链接关系。
综上所述，循环单链表在循环遍历和插入/删除操作上比普通单链表更方便。
 * */
struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* initializeList() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head; // 形成循环链表
    return head;
}

int main() {
    Node* head = initializeList();
    cout << "循环单链表已创建" << endl;
    return 0;
}



//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_1_循环单链表定义_H
#define ALGORITHMNOTESBUILDING_1_循环单链表定义_H

#endif //ALGORITHMNOTESBUILDING_1_循环单链表定义_H
