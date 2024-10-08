#include "../../1-结构化定义/0-基础函数库集合.h"
// 实现栈的基本功能、返回栈中最小元素的操作
// pop push getMin 时间复杂度设置 O(1)
using namespace std;

// stack STL : .push(elem) \ .pop() \ .top() \.empty() \.size()

class getMinSolution{
public:
	void getMinPush(elemType newNum)
	{
		if(stackMin.empty()){	// 若stackMin为空，则 直接push value
			stackMin.push(newNum);
		}
		else if(newNum <= getmin()){
			stackMin.push(newNum);
		}
		else;
		stackData.push(newNum);
	}
	elemType getMinPop()
	{
		if(stackData.empty()){
			printf("Your stackData is empty.\ngetMinPop Done...\n");
		}
		elemType value = stackData.top();
		stackData.pop();
		if(value == getmin()){	// 要删除的值 也在 stackMin 之中，需要一同删除
			stackMin.pop();
		}
		return value;
	}
	elemType getmin()
	{
		if(stackMin.empty()){
			printf("Your stackMin is empty.\ngetMinPop Done...\n");
		}
		return stackMin.top();
	}
	elemType getMinTop(){
		if(stackData.empty()){
			printf("Your stackData is empty.\ngetMinPop Done...\n");
		}
		return stackData.top();
	}
private:
	stack<elemType > stackData;
	stack<elemType > stackMin;
};



// 使用两个栈，一个用来保存当前栈中的元素，记为stackData；另一个用于保存每一步的最小值，记为stackMin

// 第一种，设当前数据 newNum ，先压入 stackData， 判断 stackMin 是否为空
/*压入*/
// stackMin 为空 ，newNum 也压入 stackMin
// stackMin 不为空， 比较 newNum 与 stackMin 栈顶哪个更小：
//													newNum 更小或相等， newNum 压入 stackMin
//													newNum 更大，	  stackMin 不压入内容
/*弹出*/
// 先弹出 stackData，比较 stackMin的值 与 栈顶弹出值value	（stackMin 由 stackData 演进，逐渐变小）
// 比较 value 与 stackMin：  stackMin 只会 <= value
//	   value > stackMin： stackMin不弹出栈顶，返回value
//	   value = stackMin： stackMin弹出栈顶元素
/*查找最小值*/
// stackMin 栈顶 当前 stackData 最小值

// 栈打印








//
// Created by 陈至宇 on 2024/5/13.
//

#ifndef ALGORITHMNOTESBUILDING_1_设计一个有GETMIN功能的栈_H
#define ALGORITHMNOTESBUILDING_1_设计一个有GETMIN功能的栈_H

#endif //ALGORITHMNOTESBUILDING_1_设计一个有GETMIN功能的栈_H
