
//
// Created by 陈至宇 on 2022/2/22.
//

#include <cstdio>
#include <unistd.h>

//从后往前的方向 1.范围变大 2。循环内插入排 3。
// 不断移动直至合适
void InsertSort(int *A, int length) // 递增序列；temp<A[j-1] 以及
{
    for (int i = 1; i < length; ++i) {
        int temp = A[i], j = i;
        while (j > 0 && temp < A[j - 1]) {
            // TODO 插入排序 算法思想::向前移动，每当判断后面的值temp=A【i】比A【j-1】，j=i先；更大小时，则进行置换
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
        for (int k = 0; k < length; ++k) {
            printf("%d\t", A[k]);
        }
        printf("\n");
        sleep(1);
    }

}

void InsertSor_H(int *A, int length) {
    for (int i = 1; i < length; ++i) {
        int temp = A[i], j = i;
        while (j > 0 && temp > A[j - 1])  // 大就往前移，没那么大就跳出循环
        {
            A[j] = A[j - 1];  // 意味着temp向前移，另一个角度是j全部向后推了
            j--;
        }
        // 一直移动到 temp < A[j-1], 此时应该把temp赋予在j？？？✅
        A[j] = temp;
        // 打印序列
        for (int k = 0; k < length; ++k) {
            printf("%d\t", A[k]);
        }
        printf("\n");
        sleep(1);
    }
}

void hereIam() {
    printf("I am from diff file.\n");
}