#include "../1-结构化定义/0-基础函数库集合.h"
using namespace std;
// 编写类，两个栈实现队列，支持队列基本操作 add poll peek || .front .back .push .pop .size .empty

// add        增加一个元索                     如果队列已满，则抛出一个IIIegaISlabEepeplian异常
// poll         移除并返问队列头部的元素    如果队列为空，则返回null
// peek       返回队列头部的元素             如果队列为空，则返回null

// 一个栈作为 压入栈，记为 stackPush；另一个栈作为弹出栈，记为 stackPop
// 要求
// 1. 只要 stackPop 不空，则 stackPush 不压入 stackPop
// 2. 如果 stackPop 为空，则 stackPush 一次性全部压入 stackPop

class twoStacksQueueSolution{
public:
	// simulating queue normal act : .add .poll .peek
	void twoStacksQueueAdd(elemType newNum){
		stackPush.push(newNum);
		pushToPop();
	}
	elemType twoStacksQueuePoll(){
		if(stackPush.empty() && stackPop.empty())
			printf("Your Queue is empty!");
		pushToPop();
		elemType oldNum = stackPop.top();
		stackPop.pop();
		return oldNum;
	}
	elemType twoStacksQueuePeek(){
		if(stackPush.empty() && stackPop.empty())
			printf("Your Queue is empty!");
		pushToPop();
		return stackPop.top();
	}
	bool twoStacksQueueEmpty(){
		if(stackPush.empty() && stackPop.empty())
			return true;
		else{
			pushToPop();
			return false;
		}
	}
private:
	stack<elemType > stackPush;
	stack<elemType > stackPop;

	void pushToPop()
	{
		if(stackPop.empty()){	// 只要 stackPop 为空，则可以进行倒入stackPop操作
			while(!stackPush.empty()){	// 倒入操作，一直到 stackPush 为空
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
	}
};







//
// Created by 陈至宇 on 2024/5/10.
//

#ifndef ALGORITHMNOTESBUILDING_由两个栈组成的队列_H
#define ALGORITHMNOTESBUILDING_由两个栈组成的队列_H

#endif //ALGORITHMNOTESBUILDING_由两个栈组成的队列_H
