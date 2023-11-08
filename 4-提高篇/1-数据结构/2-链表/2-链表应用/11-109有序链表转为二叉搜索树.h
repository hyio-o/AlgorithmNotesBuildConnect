#include "../../0-初始化定义/2-链表定义.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 如果链表为空，则返回空树。
        if(head == NULL)    return NULL;
        // 如果链表只有一个节点，则直接将该节点转换为树并返回。
        if(head->next == NULL)  return new TreeNode(head->val);
        // 如果链表有多个节点，我们需要找到链表的中间节点，
        // 将其作为二叉搜索树的根节点。然后递归地将链表分成两部分：
        // 前半部分和后半部分，再将它们转换为左子树和右子树。
        ListNode* slow = head;
        ListNode* fast = head;  // 使用fast指针快速移动到链表的中间位置。
        // 这样slow指针就会指向链表的中间节点。
        ListNode* slowPre = slow;   //slowPre用于记录slow指针的前一个节点。
        while(fast != NULL && fast->next != NULL){
            slowPre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 断开slow前面的节点和slow的连接，即将中间节点之前的部分断开。
        // 此时，链表被分成两部分：前半部分和后半部分。
        slowPre->next = NULL;
        // 创建一个新的树节点，其值为中间节点的值，并递归地将前半部分和后半部分链表转换为左子树和右子树。
        return new TreeNode(slow->val, sortedListToBST(head), sortedListToBST(slow->next));
    }

};


/*
 * 这段代码是一个将已排序的链表转换为二叉搜索树的函数。下面我将详细解读这段代码，并使用一个案例来解释其工作原理。
首先，我们来了解一下这段代码的基本思路：
如果链表为空，则返回空树。
如果链表只有一个节点，则直接将该节点转换为树并返回。
如果链表有多个节点，我们需要找到链表的中间节点，将其作为二叉搜索树的根节点。然后递归地将链表分成两部分：前半部分和后半部分，再将它们转换为左子树和右子树。
现在我们逐步解读代码：
初始化指针slow和fast都指向链表的头部。slowPre用于记录slow指针的前一个节点。
使用fast指针快速移动到链表的中间位置。这样slow指针就会指向链表的中间节点。
断开slow前面的节点和slow的连接，即将中间节点之前的部分断开。此时，链表被分成两部分：前半部分和后半部分。
创建一个新的树节点，其值为中间节点的值，并递归地将前半部分和后半部分链表转换为左子树和右子树。
现在我们用一个案例来解释这个过程：
假设我们有以下已排序的链表：1 -> 2 -> 3 -> 4 -> 5。
首先，我们初始化指针head指向链表的头部节点1。
然后，我们进入循环，将fast指针移动到链表的中间位置。在这个例子中，中间位置是节点3。此时，slowPre指向节点1，slow指向节点3。
我们断开slowPre->next的连接，即断开节点1和节点3之间的连接。此时，链表被分成两部分：1 -> 2和4 -> 5。
我们创建一个新的树节点，其值为3（即中间节点的值），并递归地将前半部分链表（1 -> 2）转换为左子树，将后半部分链表（4 -> 5）转换为右子树。
最后，我们返回这个新创建的树节点。
这样，我们就将已排序的链表转换为了一个二叉搜索树。这个二叉搜索树的根节点为3，左子树为1 -> 2，右子树为4 -> 5。
 * */
//
// Created by 陈至宇 on 2023/11/4.
//

#ifndef ALGORITHMNOTESBUILDING_11_109有序链表转为二叉搜索树_H
#define ALGORITHMNOTESBUILDING_11_109有序链表转为二叉搜索树_H

#endif //ALGORITHMNOTESBUILDING_11_109有序链表转为二叉搜索树_H
