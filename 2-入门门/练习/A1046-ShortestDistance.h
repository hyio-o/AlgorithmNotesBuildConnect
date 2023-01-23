// 题： N个结点为一个圈， 已知相邻两个点之间的距离，每次只能移动到相邻结点；求最短路径
// 思路：
// 法一： 使用前后扫描的方式，比较出最短路径；； 采用地址编号A到地址编号B方式
// distance(left, right) 比较 sum-distance(left, right) ：：因为圈圈
#include <cstdio>

int distance(int *A, int left, int right, int len) {
    if (len < 3)
        return 0;
    int distant = 0;
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += A[i];
    }
    if (left > right) {
        left = left ^ right;
        right = left ^ right;
        left = right ^ left;
    }
    for (int i = left; i < right; ++i) {
        distant += A[i];
    }
    if ((sum - distant) > distant)
        return distant;
    else
        return (sum - distant);
}


//
// Created by 陈至宇 on 2022/3/19.
//

#ifndef ALGORITHMNOTESBUILDING_A1046_SHORTESTDISTANCE_H
#define ALGORITHMNOTESBUILDING_A1046_SHORTESTDISTANCE_H

#endif //ALGORITHMNOTESBUILDING_A1046_SHORTESTDISTANCE_H
