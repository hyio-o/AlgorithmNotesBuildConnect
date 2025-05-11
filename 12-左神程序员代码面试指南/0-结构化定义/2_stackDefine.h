#include "./1_linkListDefine.h"

// define stack class (Monotonic stack, Shared stack)
// part 1 Monotonic stack

// 1. define linkedList stack
class ZSLinkedListStack {
public:
	// 0.0 define
	// 0.1 init stack
	// 0.2 is empty stack
	bool isEmptySeqStack() {
		if (_TOP == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	// 0.3 top stack
	elemType topSeqStack() {
		if (!isEmptySeqStack()) {
			return myStack.getTail();
		}
		return false;
	}
	// 0.4 print stack
	void printSeqStack() {
		myStack.printZSLinkedList();
	}
	// 1.0 push stack
	bool pushSeqStack(elemType val) {
		_TOP++;
		myStack.addHead(val);
		return true;
	}
	// 2.0 pop stack
	elemType popSeqStack() {
		_TOP--;
		return myStack.rmHead();
	}
private:
	ZSLinkedList myStack;
	int _TOP = -1;
};
// 2. define list stack
class ZSListStack {
public:
	// 0.0 define structure
	struct ZSSeqStack {
		int TOP;	// 顺序栈地址位置index
		elemType data[myMAX];
		ZSSeqStack() {
			memset(data, 0, sizeof(data));
		}
	};
	// 0.1 init struct
	ZSListStack() {
		myStack.TOP = -1;
		// require no things
	}
	// 0.2 is empty stack
	bool isEmptySeqStack() {
		if (myStack.TOP == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	// 0.3 top stack
	elemType topSeqStack() {
		if (myStack.TOP == -1) {
			return '\0';
		}
		else {
			return myStack.data[myStack.TOP];
		}
	}
	// 0.4 print stack
	void printSeqStack() {
		while (myStack.TOP != -1) {
			printf("%d ", myStack.data[myStack.TOP]);
			myStack.TOP--;
		}
	}
	// 1.0 push stack
	bool pushSeqStack(elemType val) {
		if (myStack.TOP == myMAX - 1) {
			return false;
		}
		else {
			myStack.TOP += 1;
			myStack.data[myStack.TOP] = val;
			return true;
		}
	}
	// 2.0 pop stack
	elemType popSeqStack() {
		if (myStack.TOP == -1) {
			return '\0';
		}
		else {
			return myStack.data[myStack.TOP--];
		}
	}

private:
	ZSSeqStack myStack;
};

// part 2 Shared stack
// TODO shared stack

// memset:: void *memset(void *str, int c, size_t n)
// :str -- 指向要填充的内存块。
// c -- 要被设置的值。该值以 int 形式传 递，但是函数在填充内存块时是使用该值的无符号字符形式
// n -- 要被设置为该值的字符数。

//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_2_STACKDEFINE_H
#define ALGORITHMNOTESBUILDING_2_STACKDEFINE_H

#endif //ALGORITHMNOTESBUILDING_2_STACKDEFINE_H
