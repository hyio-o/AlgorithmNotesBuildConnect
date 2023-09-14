#include "../4-树与二叉树/1-二叉树/A-二叉树定义.h"
// 方法一：暴力解法 两层for循环
// 方法二：



//暴力
class forceSolu {
public:
    int removeElem(vector<int> &nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == val) {
                // 发现移除，集体埋葬
                for (int j = i; j + 1 < size; ++j) {
                    nums[j] = nums[j + 1];
                }
                //if(i+1 == size)     size--;
                i--;    // 下标i以后的元素都向前移动了一格，
                // 因此在整个大循环中i也就向左移动了一格
                size--;
            }
        }
        return size;
    }
};

// 双指针方法(快慢指针）
/* ：定义 两个指针一快一慢， fastInd slowInd; 快指针比慢指针多走一格
 * 扫描时就用slowInd比对，当扫描==val则快走指针多一步，用快替换慢；
 * 当扫描≠val则两个指针一起走， 最后返回slowInd
 * */
class TwoPSolu {
public:
    int removeELem(vector<int> &nums, int val) {
        int slowInd = 0;
        // 用fastInd指导前进
        for (int fastInd = 0; fastInd < nums.size(); ++fastInd) {
            if (val != nums[fastInd])
                // 实现了自动用fastInd填充slowInd;
                // 不改变元素的相对位置
                nums[slowInd++] = nums[fastInd];
        }
        return slowInd;
    }
};

// 双指针覆盖方法，改变元素相对位置
class TwoP_CoverSolu {
public:
    int removeElem(vector<int> &nums, int val) {
        int leftInd = 0;    // 最左
        int rightInd = nums.size() - 1;   // 最右
        while (leftInd <= rightInd) {
            // 找到左边等于val的元素 ， 以及右边不等于val的元素 ｜ 双向奔赴
            while (leftInd <= rightInd && nums[leftInd] != val) ++leftInd;
            while (leftInd <= rightInd && nums[rightInd] == val) --rightInd;
            // 右边≠val的元素 覆盖左边等于val的元素 ｜ 最后奔赴; 因为这个时候，
            if (leftInd < rightInd) nums[leftInd++] = nums[rightInd--];
        }
        return leftInd;
    }
private:
};



//
// Created by 陈至宇 on 2022/8/10.
//

#ifndef ALGORITHMNOTESBUILDING_27_移除元素_H
#define ALGORITHMNOTESBUILDING_27_移除元素_H

#endif //ALGORITHMNOTESBUILDING_27_移除元素_H
