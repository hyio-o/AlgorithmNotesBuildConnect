/*
 * 7'J66 - 6677 = 1089 9810- 0189 = 9621 9621-1269 = 8352 8532 - 2358 = 6174 7641 - 1467 = 6174
 * */
// 思路：1。首次计算，得出数字结果应转为字符串再进行排序/
// 格式保证输入值在（0，100000），；若得到计算N值四位数字全部相等，则输出 "N-N=0000"结束计算。
// 思路2：1。设计函数将输入n转为只有单个数值的数组之中，然后进行核排序递减
#include <cstdio>
#include <unistd.h>

//方法二：
// 此函数返回比值大小 true ｜｜ false
bool cmp(int a, int b) {
    return a > b;
}

void to_array(int n, int num[]) {
    for (int i = 0; i < 4; ++i) {
        num[i] = n % 10;
        n /= 10;
    }
}

int to_number(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum = sum * 10 + num[i];
    }
    return sum;
}

void InsertSort(int *A, int length, bool order) {
    if (order == true) {  // 递增排序 == true
        for (int i = 1; i < length; ++i) {
            int temp = A[i], j = i;
            while (j > 0 && temp < A[j - 1]) {
                // TODO 插入排序 算法思想::向前移动，每当判断后面的值temp=A【i】比A【j-1】，j=i先；更大小时，则进行置换
                A[j] = A[j - 1];
                j--;
            }
            A[j] = temp;
        }
    } else {
        for (int i = 1; i < length; ++i) {
            int temp = A[i], j = i;
            while (j > 0 && temp > A[j - 1])  // 大就往前移，没那么大就跳出循环
            {
                A[j] = A[j - 1];  // 意味着temp向前移，另一个角度是j全部向后推了
                j--;
            }
            // 一直移动到 temp < A[j-1], 此时应该把temp赋予在j？？？✅
            A[j] = temp;
        }
    }
}

/*
 * 思路：1。用to_array函数将n转换为数组并递增排序,再用to_number函数将递增排序完的数组转换为整数MIN
*2。数组递减排序,再用to—number函数将递减排序完的数组转换为整数MAX
 * 3。 令 n=MAX - MIN为下一个数,并输出当前层的信息。
 * 如果得到的n为0 或6 1 7 4 ,退出循环。
 * */
void unity() {
    int n, MIN, MAX;
    int num[5];
    scanf("%d", &n);
}


//
// Created by 陈至宇 on 2022/2/25.
//
