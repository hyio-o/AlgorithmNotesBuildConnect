#include "../1-结构化定义/0-基础函数库集合.h"
using namespace std;

// 设计两个递归函数
// 1. 递归一：将栈stack的栈底元素返回并移除
// 2. 递归二：逆序一个栈

class recursionReStack{
public:
	elemType getAndRemoveLastElement(stack<elemType> stack){
		elemType myresult = mystack.top();
		mystack.pop();
		if(mystack.empty()){
			return myresult;
		}else{
			elemType mylast = getAndRemoveLastElement(mystack);
			mystack.push(myresult);
			return mylast;
		}
	}
	void reverseStack(stack<elemType> mystack){
		if(mystack.empty()){
			return;
		}
		elemType val = getAndRemoveLastElement(mystack);
		reverseStack(mystack);
		mystack.push(val);
	}
private:
	stack<elemType> mystack;
};



//
// Created by 陈至宇 on 2024/5/14.
//

#ifndef ALGORITHMNOTESBUILDING_2_仅使用递归和栈操作逆序一个栈_H
#define ALGORITHMNOTESBUILDING_2_仅使用递归和栈操作逆序一个栈_H

#endif //ALGORITHMNOTESBUILDING_2_仅使用递归和栈操作逆序一个栈_H
