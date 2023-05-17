#include "../4-树与二叉树/1-二叉树/A-二叉树定义.h"

// 给定非递减顺序排列数组， 返回 每个数字的平方 组成新数组；
// 要求，一样按照非递减顺序排序
// 提示：可能出现负数
/*示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100]
 *  解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121]
 * */
int nums[] = {-7, -3, 2, 3, 11};
vector<int> A(nums, nums + 5);

// 暴力法：平方之后排序
//暴力排序的解法O(n + nlog n)
class force_Solu {
public:
    vector<int> sortedSquares(vector<int> &sums) {
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] *= sums[i]; // square
        }
        sort(sums.begin(), sums.end()); // quick_sort func
        return sums;
    }
};

// 双指针， 因为原先的数组是有序的， 只是在负数的平方之后可能变成最大数；
// 因此，数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
// 双指针指向头+尾， 比较法判断头尾的平方谁大，谁就放在结果集的向前尾巴上。
/*i指向起始位置，j指向终止位置。
    定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。
    front（平方） <  raar（平方） ： 终止位置 j 放置进 result k--（相当于重新排列，用双指针）
    */
// 时间复杂度为O(n)
class TwoPoSolu {
public:
    vector<int> sortEdSquares(vector<int> &A) {
        int result_tail = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int front = 0, rear = A.size() - 1; front <= rear;) {
            // 如果头部平方 <= 尾部平方 ， 则result数组的result_tail指向存放大的那个
            if (A[front] * A[front] < A[rear] * A[rear]) {
                result[result_tail--] = A[rear] * A[rear];
                rear--;
            } else {
                result[result_tail--] = A[front] * A[front];
                front++;
            }
        }
        return result;
    }
};

//
// Created by 陈至宇 on 2022/8/11.
//

#ifndef ALGORITHMNOTESBUILDING_977_有序数组的平方_H
#define ALGORITHMNOTESBUILDING_977_有序数组的平方_H

#endif //ALGORITHMNOTESBUILDING_977_有序数组的平方_H
