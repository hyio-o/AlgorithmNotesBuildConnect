#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insert(int data) {
    Node* head;
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = head;
    newNode->next = head == nullptr ? nullptr : head->next;

    if (head == nullptr) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void initializeList(Node** head) {
    *head = createNode(1);
    (*head)->next = (*head);
    (*head)->prev = (*head);
}

int main() {
    Node* head = nullptr;
    initializeList(&head);
    cout << "循环双链表已创建" << endl;
    return 0;
}

/*
 * 循环双链表相比普通双链表有以下几个优势：

1. 内存利用率更高：循环双链表不需要像单链表那样在尾部使用哨兵节点来检测链表是否结束，因此可以节省哨兵节点的内存开销。
2. 插入和删除操作更高效：在循环双链表中，头节点的前一个节点是尾节点，尾节点的下一个节点是头节点，形成一个闭环。因此，在插入和删除节点时，只需修改相邻节点的指针即可，无需像普通双链表那样需要遍历链表来找到插入或删除的位置。这使得循环双链表的插入和删除操作更加高效。
3. 适合环形数据结构：循环双链表适用于需要循环遍历的数据结构，例如在图形数据结构中，可以使用循环双链表来表示环形的边。在普通双链表中，如果需要实现环形结构，则需要手动设置环形条件并处理环形的遍历，而循环双链表则自动支持环形结构。
4. 无需特殊处理尾节点：在普通双链表中，尾节点的指针需要特殊处理，因为它的下一个节点是头节点。而在循环双链表中，尾节点的指针和其他节点的指针一样，指向下一个节点即可，无需特殊处理尾节点。

综上所述，循环双链表相比普通双链表具有更高的内存利用率、更高效的插入和删除操作、更适合环形数据结构以及无需特殊处理尾节点的优势。
 * */

//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_1_循环双链表定义_H
#define ALGORITHMNOTESBUILDING_1_循环双链表定义_H

#endif //ALGORITHMNOTESBUILDING_1_循环双链表定义_H
