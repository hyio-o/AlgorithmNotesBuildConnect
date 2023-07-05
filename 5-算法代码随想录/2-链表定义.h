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

typedef struct linkList{
    Elemtype val;
    linkList *next = NULL;
    linkList(int num) : val(num), next(NULL) {} ;// 构造节点的函数
    /*所以如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值！
     *使用方法:
     * linkList* head = new linkList(7);
     * */
};


//
// Created by 陈至宇 on 2023/2/10.
//

#ifndef ALGORITHMNOTESBUILDING_2_链表定义_H
#define ALGORITHMNOTESBUILDING_2_链表定义_H

#endif //ALGORITHMNOTESBUILDING_2_链表定义_H
