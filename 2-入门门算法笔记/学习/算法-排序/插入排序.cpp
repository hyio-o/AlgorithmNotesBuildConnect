
//
// Created by 陈至宇 on 2022/2/22.
//

#include <cstdio>

//从后往前的方向 1.范围变大 2。循环内插入排 3。
// 不断移动直至合适
void InsertSort(int *A, int length) //
{
    for (int i = 2; i < length; ++i) {
        int temp = A[i], j = i;
        while (j > 1 && temp < A[j - 1]) {
            // TODO 插入排序 算法思想::向前移动，
            //  每当判断后面的值temp=A【i】比A【j-1】，j=i先；更大小时，则进行置换
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
        for (int k = 0; k < length; ++k) {
            printf("\n\n%d\t", A[k]);
        }
    }

}

void hereIam() {
    printf("I am from diff file.\n");
}