#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
//#include "./1-栈定义.h"

#define MMAXN 1000

using namespace std;

typedef int Elemtype;

Elemtype pre_OrderL[] = {1, 2, 4, 3, 5, 7, 6};
Elemtype in_OrderL[] = {2, 4, 1, 5, 7, 3, 6};



// restruct BiTNode
typedef struct DMBiTNode {
	Elemtype data;
	struct DMBiTNode *lchild, *rchild;
} DMBiTNode, *DMBiTree;

struct DMTreeNode {
	int val;
	DMTreeNode *left;
	DMTreeNode *right;
	DMTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 双亲、孩子链表、双亲孩子、孩子兄弟
// 1. 双亲实现：--找双亲容易，找孩子难
// 定义数组结构存放树的结点，每个结点含两个域：
//数据域：存放结点本身数据信息。
//双亲域：指示本结点的双亲结点在数组中的位置。
//这样的存储结构，根据结点parent指针很容易找到它的双亲结点，所用时间复杂度为O(1)，
// * 直到parent为-1时，找到了树的根结点，但是我们要知道结点的孩子是什么，对不起，请遍历整个结构才行。
// * 找双亲容易，找孩子难。



struct DMParNode{
	Elemtype data;
	int parent; // 静态链表 指针域，双亲在数组下标
};
struct DMParTree{
	DMParNode nodes[MMAXN];
	int index, num; // 根节点位置、节点个数
};

// 2. 孩子链表--找孩子易，找双亲难
typedef struct DMCTNode{
	// 孩子节点 链表
	int child;
	struct DMCTNode* next;
}*DMChildPtr;

struct DMCTBox{
	// 表头结构
	Elemtype data;
	DMChildPtr firstchild;
};

typedef struct DMCTree{
	DMCTBox nodes[MMAXN];
	int index, num; // 根节点位置、节点个数
}DMsyruct;

// 3. 孩子兄弟表示法任意一棵树，它的结点的第一个孩子如果存在就是唯一的，它的右兄弟如果存在也是唯一的。
 // 因此，我们用 二叉链表作树的存储结构，链表中每个结点的两个指针域分别指向第一个孩子结点和此结点的下一个兄弟结点

typedef struct DMCSNode{
	Elemtype data;
	struct DMCSNode *firstChild, *nextSibling;
}DMCSNode, *DMCSTree;


// stack define
//
typedef struct DMSqStack {
	DMBiTNode *data[MMAXN];
	int top;

	DMSqStack() {
		top = -1;
	}
} SqStack;

void initStack(DMSqStack Sq) {
	Sq.top = -1;
}

bool Push(DMSqStack &Sq, DMBiTNode *el) {
	if (Sq.top == MMAXN - 1)
		return false;
	Sq.data[++Sq.top] = el;
	return true;
}

bool Pop(DMSqStack &Sq, DMBiTNode *&el) {
	if (Sq.top == -1)
		return false;
	el = Sq.data[Sq.top--];
	return true;
}

bool isEmptySq(DMSqStack Sq) {
	if (Sq.top == -1) return true;
	return false;
}

bool getTop(DMSqStack Sq, DMBiTNode *&el) {
	if (Sq.top == -1) return false;
	el = Sq.data[Sq.top];
	return true;
}

DMBiTree lastEle(DMSqStack Sq) {
	return Sq.data[0];
}

int count_n = 0;

void visit(DMBiTNode *T) {
	if (T) {
		printf(":%d  ", T->data);
		//if(T->lchild) printf("    T.lchild==%d    ", T->lchild->data);
		//if(T->rchild) printf("    T.rchild==%d    ", T->rchild->data);
	}
	++count_n;
	//if(count_n%3 == 0)    printf("\n");
}

// seQueue
// 定义队列
typedef struct DMSeQueue {
	DMBiTNode *data[MMAXN];
	int front, rear;
	DMSeQueue() {
		front = 0, rear = 0;
		for (int i = 0; i < MMAXN; ++i) {
			data[i] = nullptr;
		}
	}
} SeQueue;

bool isEmptySe(DMSeQueue Se) {
	if (Se.front == Se.rear)
		return true;
	else
		return false;
}
bool isFullSe(DMSeQueue Se) {
	if ((Se.rear + 1) % MMAXN == Se.front)
		return true;
	else
		return false;
}

// EnQueue
void enQueue(DMSeQueue &Se, DMBiTNode *T) {
	if (!isFullSe(Se)) {
		Se.data[Se.rear] = T;
		Se.rear = (Se.rear + 1) % MMAXN;
	}
}
// DeQueue
void deQueue(DMSeQueue &Se, DMBiTNode *&T) {
	if (!isEmptySe(Se)) {
		T = Se.data[Se.front];
		Se.front = (Se.front + 1) % MMAXN;
	}
}
// count queue
int countQueue(DMSeQueue Se) { return (Se.rear - Se.front + MMAXN) % MMAXN; }

//
// Created by 陈至宇 on 2022/3/13.
//


