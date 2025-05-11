#include <cstdlib>
#include <cstdio>
#include <iostream>

typedef int element;    //定义元素
typedef int ElemType;   //
//定义结点类型
typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}*LinkList; //listNode： 结点的类型。*LinkedList指向结点的 指针类型

//单链表初始化
LinkList ZSinitList(){
    ListNode *L;
    L = (ListNode*)malloc(sizeof(ListNode));
    if(!L)
        exit(0);
    L->next = NULL;
}   //需要养成创建是否失败的认证的习惯；（一旦失败后果不堪设想）

// 重构
//
// 单链表 定义
struct ListNode_Re {
	int val;  // 节点上存储的元素
	ListNode_Re *next;  // 指向下一个节点的指针
	ListNode_Re(int x) : val(x), next(NULL) {}  // 节点的构造函数
	// 	所以如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值！
};
// 双链表
struct DoublyLinkList_Re {
	int val;
	DoublyLinkList_Re *rear;
	DoublyLinkList_Re *front;
	DoublyLinkList_Re(int x): val(x), rear(NULL), front(NULL) {}    // 节点内构造函数

};
// 循环链表 -苟同 双链表，且首尾相连
struct CircularLinkList_Re {
	int val;
	CircularLinkList_Re *rear;
	CircularLinkList_Re *front;
	CircularLinkList_Re(int x): val(x), rear(NULL), front(NULL) {}
};

// 原链表删除操作 不带头结点需要区分 删 头节点 否
class ListNodeSolution{
public:
	ListNode_Re *removeElements_NoHead(ListNode_Re *head, int val)     // 根据值 删除链表结点
	{
		// 删的是头结点 ：只要将头结点向后移动一位就可以
		while(head != NULL && head->val == val){    // 为什么不是 if：
			ListNode_Re *temp = head;
			head = head->next;
			delete temp;
		}
		// 删 非 头结点
		ListNode_Re *cur = head;
		while(cur != NULL && cur->next != NULL){
			if(cur->next->val == val){      // 使用 cur 表示 删除节点cur.next 的前一个结点 ，后移一位表示删除
				ListNode_Re *temp = cur->next;  // 待释放/删除 结点
				cur->next = cur->next->next;
				delete temp;
			}
			else{
				cur = cur->next;    // cur结点不为空 且 cur.next结点不为空 ，然而cur.next.val 不等于 val；即
				//  cur 指针 链表结点向后移动
			}
		}
	}
	ListNode_Re *removeElements_Head(ListNode_Re *head, int val)
	{
		ListNode_Re *dummyHead = new ListNode_Re(0); // 设置一虚拟头结点
		dummyHead->next = head;         // 将 头结点 指向 虚拟头结点， 方便后续操作
		ListNode_Re *cur = dummyHead;
		while(cur->next != NULL)
		{
			if(cur->next->val == val){
				ListNode_Re *temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			}else{
				cur = cur->next;
			}
		}
		// 虚拟头结点 进行回收 销毁 返回 head 头结点
		head = dummyHead->next;
		delete dummyHead;
		return head;
	}
};


// 707.设计链表
//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
class DesignLinkList707LC{
private:
	// 定义 链表数据结构
	struct LinkedNode{
		ElemType val;
		int ListLength = 0;
		LinkedNode *next;
		LinkedNode(int val):val(val), next(nullptr){}
	};
public:
	// 1. init LinkList
	LinkedNode * initLinkList(){
		LinkedNode *dummyHead = (LinkedNode *)malloc(sizeof(LinkedNode));
		dummyHead->next = NULL;
		return dummyHead;
	}
	ElemType yourGetElemIndex(LinkedNode *obj, int index){
		LinkedNode *cur = obj->next;    // 解头结点
		for (int i = 0; cur != NULL; ++i) {
			if(i == index){
				return cur->val;
			}else{
				cur = cur->next;
			}
		}
		return -1;
	}
};
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，
// 则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。



// 创建单链表-头插


// 创建单链表-尾插




class SsolutionNode{
public:


    typedef struct LNode{   // define struct
        ElemType data;
        struct LNode *next;
    }LNode, * LinkList;

    bool initLinkList_H(LNode* &L){  // init
        L = (LNode*)malloc(sizeof (LNode));
        if(!L){
            return false;
        }
        else{
            L->next = NULL;
            return true;
        }
    }

    LinkList initLinkList_P(){  // initiate 参数传递
        LNode *L;
        L = (LNode*) malloc(sizeof (LNode));
        if(!L)
            return NULL;
        else
            L->next = NULL;
        return L;
    }

    bool insertList_H(LinkList &L, ElemType el){    // insert head 头插
        LNode *temp = (LNode*) malloc(sizeof (LNode));
        if(!temp)
            return false;
        else{
            temp->data = el;
            temp->next = L->next;
            L->next = temp;
            return true;
        };
    }

    bool insertList_T(LinkList &L, ElemType el){    // insert tail 尾插
        /*LNode *post_ptr = L->next;
    //    LNode *temp_ptr = (LNode*) malloc(sizeof (LNode));
        while (post_ptr->next != NULL){
            post_ptr = post_ptr->next;
        }
        insertList_H(post_ptr, el);*/
        while (L->next != NULL){
            L = L->next;
        }
        LNode *temp = (LNode*) malloc(sizeof (LNode));
        if(!temp)
            return false;
        else{
            temp->data = el;
            temp->next = L->next;
            L->next = temp;
            return true;
        };

        return true;
    }

    bool insertList_O_H(LinkList &L, int ad, ElemType el){  // order 按位序插入，循环链表 O(N)
        if(ad<1)
            return false;
        else{
            int erg_ad = 1;// ergodic=遍历 , erg_ad < ad
            LNode *erg_ptr = L;
            while ((erg_ad < ad)&&(erg_ptr != NULL)){   // 遍历至 ad
                erg_ptr = erg_ptr->next;
                erg_ad++;
            }
            if(!erg_ptr)
                return false;
            else{
                LNode *temp = (LNode*) malloc(sizeof (LNode));
                temp->data = el;
                temp->next = erg_ptr->next;
                erg_ptr->next = temp->next;
                return true;
            }
        }
    }

    bool deleteList_O_H(LinkList &L, int ad){
        if(ad<1 || !L)
            return false;
        else{
            int erg_ad = 1;
            LNode *pre_ptr = NULL;
            LNode *erg_ptr = L->next;
            while ((erg_ptr != NULL) && (erg_ad < ad)){
                pre_ptr = erg_ptr;
                erg_ptr = erg_ptr->next;
                erg_ad++;
            }
            if(!erg_ptr)
                return false;
            else{   // 删除 erg_ptr, pre = pre_ptr
                pre_ptr->next = erg_ptr->next;
                free(erg_ptr);
                return true;
            }
        }
    }

    LinkList findElem(LinkList L, ElemType el){ // 查找链表， 按值查找
        LNode *erg_ptr = L->next;
        while (!erg_ptr->next){
            if(erg_ptr->data == el){
                return erg_ptr;
            }

            else{
                erg_ptr = erg_ptr->next;
            }
        }
        return nullptr;
    }

    void viewLinkList(LNode *L){
        printf("(");
        LinkList temp = L->next;
        while(temp){
            printf(" %d ",temp->data);
            temp = temp->next;
        }
        printf(")view done.\n");
        return;
    }

};

//
// Created by 陈至宇 on 2023/5/15.
//

#ifndef ALGORITHMNOTESBUILDING_2_链表定义_H
#define ALGORITHMNOTESBUILDING_2_链表定义_H

#endif //ALGORITHMNOTESBUILDING_2_链表定义_H
