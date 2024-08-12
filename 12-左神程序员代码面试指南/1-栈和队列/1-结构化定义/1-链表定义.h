#include "0-基础函数库集合.h"



typedef struct ZListNode{
	elemType val;
	ZListNode *next;
	ZListNode(int x): val(x), next(NULL) {}
}*ZLinkList;

// init
ZLinkList initList(){
	ZListNode *dummyHead;
	dummyHead = (ZListNode*) malloc(sizeof (ZListNode));
	dummyHead->val = 0;
	return dummyHead;
}

// removeElem
class ZRemoveElemSolution{
public:
	ZListNode *removeElement_NoHead(ZListNode *head, elemType val){
		// 1. 删头结点 , 使用 while 可以将头结点以及后部分带有相同 val 值的链表结点删除
		while(head != NULL && head->val == val){
			ZListNode *temp = head;
			head = head->next;
			delete temp;
		}
		// 2. 删非头结点
		ZListNode *cur = head;
		while(cur != NULL && cur->next != NULL){	// 被删节点 与 被删父结点 都存在才执行删除
			// 该删的是 cur->next ：：被删节点
			if(cur->next->val == val){
				ZListNode *temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			}
			else{
				cur = cur->next;
			}
		}
		return cur;
	}
	void deleteAtIndex_ZLN(ZListNode *head, int index){

	}
};



class ZInsertElemSolution{
public:
	// 0.1. get_index return index pointing value
	elemType get_index(ZListNode *head, int index)
	{
		ZListNode *cur = head->next;	// 含头结点
		for (int i = 0; i < index && cur != NULL; ++i) {
			if(i == index)	return cur->val;
			else
				cur = cur->next;
		}
		return INT_MIN;
	}
	// 0.2. get_val return yourVal matching index
	// while val not been found, will return an error index value -1
	int get_val(ZListNode *head, elemType yourVal)
	{
		ZListNode *cur = head->next;	// 含头结点
		int index = 0;
		for (int i = 0; cur!=NULL; ++i) {
			if(cur->val == yourVal)	return index;
			else{
				index++;
				cur = cur->next;
			}
		}
		return -1;
	}

	// 1.1 addHead
	void addHead_ZLN(ZListNode* head, elemType yourVal)
	{
		ZListNode *temp = (ZListNode *) malloc(sizeof (ZListNode));
		temp->val = yourVal;
		temp->next = head->next;
		head->next = temp;
	}
	// 1.2 addTail
	void addTail_ZLN(ZListNode* head, elemType yourVal)
	{
		ZListNode* cur = head;
		// step1: move to list tail.
		while(cur->next != NULL){
			cur = cur->next;
		}// pointing the last one of list node
		ZListNode* temp = (ZListNode *) malloc(sizeof (ZListNode));
		temp->val = yourVal;
		temp->next = NULL;
		cur->next = temp;
	}
	// 1.3 addAtIndex
	void addAtIndex_ZLN(ZListNode *head, int index, elemType yourVal)
	{
		if(index == 0){
			addHead_ZLN(head, yourVal);
			return;
		}
		ZListNode *cur = head;
		for (int i = 1; cur != NULL ; ++i) {
			if(i == index){
				ZListNode *temp = (ZListNode*) malloc(sizeof (ZListNode));
				temp->val = yourVal;
				temp->next = cur->next;
				cur->next = temp;
				return;
			}
			else{
				cur = cur->next;
			}
		}
	}
};






//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_1_链表定义_H
#define ALGORITHMNOTESBUILDING_1_链表定义_H

#endif //ALGORITHMNOTESBUILDING_1_链表定义_H
