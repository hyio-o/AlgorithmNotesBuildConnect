/*
#include "../0_myCollectionOfStandardLibrary.h"

/*定义内容:
 * ZSlistNode	为链表结点
 * ZSlinkList	为链表
 * ZSinitList()
 * ZSremoveElemSolution
 *
 * ZSinsertElemSolution
 *
 * #1#

class ZSLinkedList{
public:
	// 0.0	define struct
	struct ZSlistNode{
		elemType val;
		ZSlistNode *next;
		ZSlistNode(int x): val(x), next(NULL) {}
	}*ZSlinkList;
	// 0.1	init struct
	ZSLinkedList(){
		_dummyNode = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		_dummyNode->next = nullptr;
		_dummyNode->val = -1;
		_size = 0;
	}
	// 0.2 print
	void printZSLinkedList(){
		// int count = head->listLen;
		ZSlistNode *cur = _dummyNode;
		printf("[ %p -->", cur);
		while (cur->next != NULL){
			printf("%d(%p)", cur->next->val, cur->next);
			printf(" --> ");
			cur = cur->next;
		}
		printf(" %p ]\n", cur->next);
		return;
	}
	// 0.3 getIndex
	elemType getIndex(int index) {
		if (index < 0 || index > _size) {
			return INT32_MIN;	// return fault value
		}
		ZSlistNode *cur = _dummyNode->next;
		while (index-- && cur != nullptr) {
			cur = cur->next;
		}
		return cur->val;
	}
	// 0.4 getHead
	// 0.5 getTail
	// 0.6 getVal, return index
	int getVal(elemType val) {
		ZSlistNode *cur = _dummyNode->next;
		int index = -1;
		for (index = 0; index < _size; index++) {
			if (cur->val == val) {
				break;
			}
			cur = cur->next;
		}
		return index;
	}
	// 0.7 getLen return int(len)
	int getLen() {
		return _size;
	}
	// 1.0 insert or add Head
	// 1.1 addHead
	void addHead(elemType val) {
		ZSlistNode *tmp = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		tmp->val = val;
		tmp->next = _dummyNode->next;
		_dummyNode->next = tmp;
		_size++;
		return;
	}
	// 1.2 addTail
	void addTail(elemType val) {
		ZSlistNode *tmp = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		tmp->val = val;
		tmp->next = nullptr;
		ZSlistNode *cur = _dummyNode->next;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = tmp;
		_size++;
		return;
	}
	// 1.3 addIndex
	void addAtIndex(elemType val, int index) {
		if (index < 0 || index > _size) {
			return;
		}
		ZSlistNode *cur = _dummyNode->next;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		ZSlistNode *tmp = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		tmp->val = val;
		tmp->next = cur->next;
		cur->next = tmp;
		_size++;
		return;
	}
	// 2.0 delete or remove
	// 2.1 rmHead
	void rmHead() {
		ZSlistNode *cur = _dummyNode->next;
		ZSlistNode *tmp = cur->next;
		free(cur);
		_dummyNode->next = tmp;
		_size--;
		return;
	}
	// 2.2 rmTail
	void rmTail() {
		ZSlistNode *cur = _dummyNode->next;
		ZSlistNode *tmp = cur->next;
		while (tmp->next != nullptr) {
			cur = cur->next;
			tmp = tmp->next;
		}
		cur->next = nullptr;
		free(tmp);
		_size--;
		return;
	}
	// 2.3 rmAtIndex
	void rmAtIndex(int index) {
		if (index < 0 || index > _size || !_dummyNode->next) {
			return;
		}
		ZSlistNode *cur = _dummyNode;
		ZSlistNode *tmp = cur->next;
		for (int i = 0; i < index && cur->next != nullptr; i++) {
			cur = cur->next;
			tmp = tmp->next;
		}
		cur->next = tmp->next;
		free(tmp);
		_size--;
		return;
	}
private:
	int _size = 0;
	ZSlistNode *_dummyNode;

};




//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_1_链表定义_H
#define ALGORITHMNOTESBUILDING_1_链表定义_H

#endif //ALGORITHMNOTESBUILDING_1_链表定义_H
*/
