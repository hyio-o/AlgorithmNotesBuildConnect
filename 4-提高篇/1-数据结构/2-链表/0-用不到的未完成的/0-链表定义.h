// 链表类型： 1.单链表 、 2.双链表 、 3.循环链表， 其只需要定义时多出 pre 节点
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef int Elemtype;
const int MMAXN = 1000;


class linkList {
public:
    struct linkedNode {
        int val;
        linkedNode *next;
        linkedNode(int num) : val(num), next(NULL) {} ;// 构造节点的函数
        /*所以如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值！*/
    };
};

struct ListNode{
    Elemtype val;
    ListNode *next;
}* LinkList;


//
// Created by 陈至宇 on 2022/9/23.
//

#ifndef ALGORITHMNOTESBUILDING_链表定义_H
#define ALGORITHMNOTESBUILDING_链表定义_H

#endif //ALGORITHMNOTESBUILDING_链表定义_H
