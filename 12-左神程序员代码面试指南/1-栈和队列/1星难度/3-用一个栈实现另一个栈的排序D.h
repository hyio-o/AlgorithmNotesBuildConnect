#include "../1-结构化定义/0-基础函数库集合.h"

using namespace std;

// 栈中元素为整型，想将栈从 顶到底 按 从大到小 顺序排序，只许申请一个栈；可以申请新的变量，不能申请额外数据结构

// 将要排序的栈记为mystack ，申请的辅助栈记为 helpstack。
// 在 mystack 上执行pop操作， 弹出的元素记为 cur。


void func(){
	stack<int> mystack;
	stack<int> helpstack;


	int num, yourval, cur , length_mystack;
	cin>>num;
	while(num--){
		cin>>yourval;
		mystack.push(yourval);
	}

	while(!mystack.empty())
	{
		cur = mystack.top();    mystack.pop();
		if(helpstack.empty()){helpstack.push(cur);}
		else if(cur <= helpstack.top()){
			helpstack.push(cur);
		}
		else{
			while(!helpstack.empty() && cur > helpstack.top()){
				// 装回去
				mystack.push(helpstack.top());
				helpstack.pop();
			}
			helpstack.push(cur);
		}
	}
	num = mystack.size();
	for(int i = 0; i<num; i++){
		printf("%d ", mystack.top());
		mystack.pop();
	}
}


//
// Created by 陈至宇 on 2024/5/14.
//

#ifndef ALGORITHMNOTESBUILDING_3_用一个栈实现另一个栈的排序_H
#define ALGORITHMNOTESBUILDING_3_用一个栈实现另一个栈的排序_H

#endif //ALGORITHMNOTESBUILDING_3_用一个栈实现另一个栈的排序_H
