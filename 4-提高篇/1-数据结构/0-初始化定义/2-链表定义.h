#include <cstdlib>
#include <cstdio>
#include <iostream>

typedef int element;    //定义元素
typedef int ElemType;   //
//定义结点类型
typedef struct ListNode{
    ElemType data;
    struct ListNode *next;
}*LinkList; //listNode： 结点的类型。*LinkedList指向结点的 指针类型

//单链表初始化
LinkList initList(){
    ListNode *L;
    L = (ListNode*)malloc(sizeof(ListNode));
    if(!L)
        exit(0);
    L->next = NULL;
}   //需要养成创建是否失败的认证的习惯；（一旦失败后果不堪设想）

// 创建单链表-头插


// 创建单链表-尾插




class solutionNode{
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
