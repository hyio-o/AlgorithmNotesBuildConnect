#include "../../0-初始化定义/2-链表定义.h"


//定义存储结构
typedef struct {
    int date;//这里为图方便，只以int数据类型为例子
}Date;

typedef struct LNode {
    Date elem;
    struct LNode *next;
}Lnode ,*Linklist;

//单链表初始化
int InitList(Linklist &L)//&L可以直接对L操作，用到的是c++的部分知识，这样不用返回结构体
{
    L=(Linklist)malloc(sizeof(LNode));//c语言开辟空间
    //L=new Lnode;c++语言开辟空间
    L->next=NULL;//头节点指针域置为空
    return 1;//初始化完毕
}


// 递增La， Lb， Lc

class solution_merge{
    ListNode* mergeTwoLists(ListNode* la, ListNode* lb) {
        if (la == NULL) {
            return lb;
        }
        if (lb == NULL) {
            return la;
        }
        if (la->data < lb->data) {
            la->next = mergeTwoLists(la->next, lb);
            return la;
        } else {
            lb->next = mergeTwoLists(la, lb->next);
            return lb;
        }
    }

    void Merge_List(LinkList La, LinkList Lb, LinkList Lc){
        LinkList tempA = La->next;      // 工作指针,
        LinkList tempB = Lb->next;    // 工作指针,
        LinkList tempC = La;    // 插入方法
        Lc = tempC;
        while(tempA && tempB){  // 遍历两个链表直到结束
            // tempA.data < tempB.data
            // tempA.data > tempB.data
            // else
            if(tempA->data < tempB->data){
                tempC->next = tempA;
                tempC = tempA;
                tempA = tempA->next;
            }
            else if(tempA->data > tempB->data){
                tempC->next = tempB;
                tempC = tempB;
                tempB = tempB->next;    // tempB++;
            }
            else{   // 取tempA，舍去tempB
                tempC->next = tempA;
                tempC = tempA;
                tempA = tempA->next;
                LinkList rejectTEMP = tempB->next;
                delete tempB;
                tempB = rejectTEMP;
            }
        }
        tempC->next = tempA ? tempA : tempB;
        delete Lb;
    }

    void MergeList(Linklist &La,Linklist &Lb,Linklist &Lc)
    {//合并链表La和Lb，合并后的新表使用头指针Lc指向
        Linklist pa=La->next;  Linklist pb=Lb->next;
        //pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点
        Linklist pc;
        Lc=pc=La;  //用La的头结点作为Lc的头结点
        while(pa && pb)//到任意一个链表的尾节点结束
        {
            if(pa->elem.date<pb->elem.date){
                pc->next=pa;
                pc=pa;
                pa=pa->next;
            }
                //取较小者La中的元素，将pa链接在pc的后面，pa指针后移
            else if(pa->elem.date>pb->elem.date) {pc->next=pb; pc=pb; pb=pb->next;}
                //取较小者Lb中的元素，将pb链接在pc的后面，pb指针后移
            else //相等时取La中的元素，删除Lb中的元素
            {pc->next=pa;pc=pa;pa=pa->next;
                Linklist q=pb->next;delete pb ;pb =q;//free(pb);也可以
            }
        }
        pc->next=pa?pa:pb;    //插入剩余段
        delete Lb;            //释放Lb的头结点
    }
private:
    //后插法创建单链表
    void CreateList(Linklist &L,int n)//同样也用到了c++引用的知识
    {   //n为用户要输入的个数
        Linklist r;//创建尾指针
        r=L;//指向头节点
        for(int i=0;i<n;i++)
        {
            Linklist p=new LNode;//开辟空间，p为节点
            printf("请输入第%d个数字\n",i+1);
            scanf("%d",&p->elem.date);//别忘取&
            //
            p->next=NULL;
            r->next=p;//将新节点插入r之后
            r=p;//r指向新的尾节点
        }

    }
};

//输出数据
void output(Linklist L)
{
    Linklist p=L;
    p=L->next;
    while(p)
    {
        printf("%2d",p->elem.date);
        p=p->next;
    }
}
//
// Created by 陈至宇 on 2023/10/27.
//

#ifndef ALGORITHMNOTESBUILDING_7_合并链表_H
#define ALGORITHMNOTESBUILDING_7_合并链表_H

#endif //ALGORITHMNOTESBUILDING_7_合并链表_H
