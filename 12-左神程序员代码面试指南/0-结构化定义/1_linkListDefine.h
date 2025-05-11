#include "0_myCollectionOfStandardLibrary.h"

/*
 * addTail(),尾部插入元素O(n),使用了while循环;
 */
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
	elemType getHead() {
		ZSlistNode *cur = _dummyNode;
		return cur->next->val;
	}
	// 0.5 getTail
	elemType getTail() {
		int tail = getLen()-1;	// 长度-1, 即为数组下标
		return getIndex(tail);
	}
	// 0.6 getVal, return index, 从0开始的下标
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
		ZSlistNode *cur = _dummyNode;
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
	elemType rmHead() {
		ZSlistNode *cur = _dummyNode->next;
		ZSlistNode *tmp = cur->next;
		elemType val = cur->val;
		free(cur);
		_dummyNode->next = tmp;
		_size--;
		return val;
	}
	// 2.2 rmTail
	elemType rmTail() {
		ZSlistNode *cur = _dummyNode->next;
		ZSlistNode *tmp = cur->next;
		while (tmp->next != nullptr) {
			cur = cur->next;
			tmp = tmp->next;
		}
		cur->next = nullptr;
		elemType val = tmp->val;
		free(tmp);
		_size--;
		return val;
	}
	// 2.3 rmAtIndex
	elemType rmAtIndex(int index) {
		if (index < 0 || index > _size || !_dummyNode->next) {
			return false;
		}
		ZSlistNode *cur = _dummyNode;
		ZSlistNode *tmp = cur->next;
		for (int i = 0; i < index && cur->next != nullptr; i++) {
			cur = cur->next;
			tmp = tmp->next;
		}
		cur->next = tmp->next;
		elemType val = tmp->val;
		free(tmp);
		_size--;
		return val;
	}
	// 3.0 clean up LinkedList
	void cleanUpLinkedList() {
		ZSlistNode *tmp;
		while (_dummyNode->next != nullptr) {
			tmp = _dummyNode->next;
			_dummyNode->next = tmp->next;
			free(tmp);
		}
		return;
	}
private:
	int _size = 0;
	ZSlistNode *_dummyNode;

};






/*定义内容:
 * ZSlistNode	为链表结点
 * ZSlinkList	为链表
 * ZSinitList()
 * ZSremoveElemSolution
 *
 * ZSinsertElemSolution
 *
 * */

/*
typedef struct ZSlistNode{
	elemType val;
	ZSlistNode *next;
	int listLen = 0;
	ZSlistNode(int x): val(x), next(NULL) {}
}*ZSlinkList;


// init
ZSlinkList ZSinitList(){
	ZSlistNode *dummyHead;
	dummyHead = (ZSlistNode*) malloc(sizeof (ZSlistNode));
	dummyHead->val = 0;
	dummyHead->next = dummyHead;	// 指向自己(如果已经生成且存在时)
	return dummyHead;
}

// print test
class ZSprintListSolution{
public:
	void printList(ZSlistNode *head){
		// int count = head->listLen;
		while (head->next != NULL){
			printf("%d", head->next->val);
			printf(" --> ");
		}
		return;
	}
};

// removeElem
class ZSremoveElemSolution{
public:
	// 根据值删除链表结点
	ZSlistNode *removeElement_NoHead(ZSlistNode *head, elemType val){
		// 1. 删头结点 , 使用 while 可以将头结点以及后部分带有相同 val 值的链表结点删除
		while(head != NULL && head->val == val){
			ZSlistNode *temp = head;
			head = head->next;
			delete temp;
		}
		// 2. 删非头结点
		ZSlistNode *cur = head;
		while(cur != NULL && cur->next != NULL){	// 被删节点 与 被删父结点 都存在才执行删除
			// 该删的是 cur->next ：：被删节点
			if(cur->next->val == val){
				ZSlistNode *temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			}
			else{
				cur = cur->next;
			}
		}
		return cur;
	}
	// 根据index删除链表节点
	void deleteAtIndex_ZLN(ZSlistNode *head, int index){
		int _size = head->listLen;
		if(index > (_size - 1) || (index < 0)){
			return;
		}
		ZSlistNode *cur = head->next;	// 此时cur指向head[0]号元素
		while(index--){
			cur = cur->next;
		}
		// 已经到了head[index]号元素,需要将head[index]指向head[index++]
		ZSlistNode *tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		head->listLen--;
	}
};



class ZSinsertElemSolution{
public:
	// 0.1. get_index return index pointing value
	elemType get_index(ZSlistNode *head, int index)
	{
		ZSlistNode *cur = head->next;	// 含头结点
		for (int i = 0; i < index && cur != NULL; ++i) {
			if(i == index)	return cur->val;
			else
				cur = cur->next;
		}
		return INT_MIN;
	}
	// 0.2. get_val return yourVal matching index
	// while val not been found, will return an error index value -1
	int get_val(ZSlistNode *head, elemType yourVal)
	{
		ZSlistNode *cur = head->next;	// 含头结点
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
	void addHead_ZLN(ZSlistNode* head, elemType yourVal)
	{
		ZSlistNode *temp = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		temp->val = yourVal;
		temp->next = head->next;
		head->next = temp;
	}
	// 1.2 addTail
	void addTail_ZLN(ZSlistNode* head, elemType yourVal)
	{
		ZSlistNode* cur = head;
		// step1: move to list tail.
		while(cur->next != NULL){
			cur = cur->next;
		}// pointing the last one of list node
		ZSlistNode* temp = (ZSlistNode *) malloc(sizeof (ZSlistNode));
		temp->val = yourVal;
		temp->next = cur->next;
		cur->next = temp;
	}
	// 1.3 addAtIndex
	void addAtIndex_ZLN(ZSlistNode *head, int index, elemType yourVal)
	{
		if(index == 0){
			addHead_ZLN(head, yourVal);
			return;
		}
		ZSlistNode *cur = head;
		for (int i = 1; cur != NULL ; ++i) {
			if(i == index){
				ZSlistNode *temp = (ZSlistNode*) malloc(sizeof (ZSlistNode));
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
*/






//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_1_链表定义_H
#define ALGORITHMNOTESBUILDING_1_链表定义_H

#endif //ALGORITHMNOTESBUILDING_1_链表定义_H
