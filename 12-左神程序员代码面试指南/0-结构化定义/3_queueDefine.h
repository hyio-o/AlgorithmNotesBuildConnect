#include "2_stackDefine.h"

// define stack class( List queue, LinkedList queue)
// part 1 List queue
class ZSListQueue {
public:
	// 0.0 define structure
	struct ZSSeqQueue {
		elemType data[myMAX];
		ZSSeqQueue() {
			memset(data, 0, myMAX * sizeof(elemType));
		}
	};
	// 0.1 init struct
	ZSListQueue() {
		_front = 0;
		_rear = 0;
		// require no things
	}
	// 0.2 isEmptySeqQueue
	bool isEmptySeqQueue() {
		if (_front == _rear) {
			return true;
		}
		else {
			return false;
		}
	}
	// 0.3 isFullSeqQueue
	bool isFullSeqQueue() {
		if ((_rear + 1) % myMAX == _front) {
			return true;
		}
		else {
			return false;
		}
	}
	// 0.4 getSizeSeqQueue
	int getSizeSeqQueue() {
		return (_rear - _front + myMAX) % myMAX;
	}
	// 0.5 printSeqQueue, 使用多分支选择结构;front < rear, front > rear
	void printSeqQueue() {
		if (!isEmptySeqQueue()) {
			int front =  _front;
			int rear = _rear;
			while (front != rear) {
				printf("[%d](%d,%d) ",myQueue.data[front], front, rear);
				front = (front+1)%myMAX;
			}
		}
		return;
	}
	// 1.0 enSeqQueue
	bool enSeqQueue(elemType val) {
		if (!isFullSeqQueue()) {
			myQueue.data[_rear] = val;
			_rear = (_rear + 1) % myMAX;
			return true;
		}
		else {
			return false;
		}
	}
	// 2.0 deSeqQueue
	elemType deSeqQueue() {
		if (!isEmptySeqQueue()) {
			elemType val = myQueue.data[_front];
			_front = (_front + 1) % myMAX;
			return val;
		}
		else {
			return false;
		}
	}

private:
	int _front, _rear;
	ZSSeqQueue myQueue;
};




//
// Created by 陈至宇 on 2024/4/29.
//

#ifndef ALGORITHMNOTESBUILDING_3_QUEUEDEFINE_H
#define ALGORITHMNOTESBUILDING_3_QUEUEDEFINE_H

#endif //ALGORITHMNOTESBUILDING_3_QUEUEDEFINE_H
