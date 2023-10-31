#include <cstdio>
// 递归归并
/* 1。 申请空间=两个已经排序序列之和
 * 2。 两个指针=最初位置为俩已经排序序列起始位置
 * 3。 比较俩指针元素， 选相对大/小 放入合并空间， 移动指针
 * 4。 重复3， 直到指针指向末尾
 * 5。 ⭐️❕将另一序列剩下所有元素直接复制到合并序列尾部
 * */
const int MAXN = 100;

//[L1,R1]==[left,mid], [L2,R2]==[mid+1,right]
void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int temp[MAXN], index = 0;    // temp 临时存放合并数组，index为下标
    while (i <= R1 && j <= R2) { // i=L1 _TO_ R1;; j=L2 _TO_ R2
        if (A[i] < A[j])
            temp[index++] = A[i++];
        else
            temp[index++] = A[j++];
    }
    // 将剩余部分元素加入序列
    while (i <= R1)temp[index++] = A[i++];
    while (j <= R2)temp[index++] = A[j++];
    for (int k = 0; k < index; ++k) {
        A[L1 + i] = temp[i];        //合并后序列赋值返回A
    }
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;       // 递归分左右， 二分法
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);  //合并子区间
    }
}

//
// Created by 陈至宇 on 2022/2/24.
//

// P2_ 非递归
void mergeSort_N(int *A) {

}


void merge_N(int *A) {

}