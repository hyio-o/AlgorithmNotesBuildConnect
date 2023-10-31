#include <iostream>
using namespace std;

void createArray(int arr[], int size) {
    if (size == 0) {
        return;
    }
    cout << "请输入第" << size << "个元素： ";
    cin >> arr[size - 1];
    createArray(arr, size - 1);
}


//
// Created by 陈至宇 on 2023/10/28.
//

#ifndef ALGORITHMNOTESBUILDING_1_递归创建数组_H
#define ALGORITHMNOTESBUILDING_1_递归创建数组_H

#endif //ALGORITHMNOTESBUILDING_1_递归创建数组_H
