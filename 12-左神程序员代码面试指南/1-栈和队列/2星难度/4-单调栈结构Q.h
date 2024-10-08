#include "../1-结构化定义/0-基础函数库集合.h"
using namespace std;

// 【题目】
//给定一个不含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。返回所有位置相应的信息。
// 返回的是数组下标
//【举例】
//    arr = {3,4,1,5,6,2,7}返回如下二维数组作为结果:
//{ {-1, 2}, { 0, 2}, {-1,-1}, { 2, 5}, { 3, 5}, { 2,-1}, { 5,-1 } }

class solution{
public:
	//vector<int> val;
	vector<int> myVal = {3,4,1,5,6,2,7};

	int *bigON2Solu(vector<int> val)
	{
		int val_len = val.size();
		 int val_res[val_len][2];
//		int **val_res = (int **) malloc(val_len * sizeof(int *));
// 无法传输二维数组 返回值
		// val_res[i][0]  equals leftLessIndex
		// val_res[i][1]  equals rightLessIndex
		for(int i = 0; i<val_len; i++){ // 初始化val_res 结果二维数组
			val_res[i][0] = val[i];
		}
		for(int i=0; i < val_len; i++){
			int leftLessIndex = -1;
			int rightLessIndex = -1;
			int cur = i-1;			// 活动指针 放置在 i 左边
			// 找左边的活动指针 指向i的左边一位，从左向右依次查找 比 val[i] 更小的值，只要找到就跳出循环 break
			while(cur >= 0){
				if(val[cur] < val[i]){
					leftLessIndex = cur;
					break;
				}
				cur--;				// 从左向右依次查找
			}
			cur = i + 1;			// 活动指针 放置在 i 右边
			while(cur < val_len){
				if(val[cur] < val[i]){
					rightLessIndex = cur;
					break;
				}
				cur++;
			}
			val_res[i][0] = leftLessIndex;
			val_res[i][1] = rightLessIndex;
		}
		return *val_res;	// 返回二维数组的第一行的首地址
	}
private:

};


//【要求】
//如果 arr 长度为 N，实现原问题和进阶问题的解法，时间复杂度都达到 O(N)。


//
// Created by 陈至宇 on 2024/9/16.
//

#ifndef ALGORITHMNOTESBUILDING_4_单调栈结构_H
#define ALGORITHMNOTESBUILDING_4_单调栈结构_H

#endif //ALGORITHMNOTESBUILDING_4_单调栈结构_H
