#include "../1-数组定义.h"
/*
 * 大题思路：滑动窗口~双指针方法 || 形容：后右面指针rear，前左面指针front；
 * 定值target， 滑动窗口数组和值sum，
 * 若sun >= target 则判定为其中一条小的连续子数组，此时前左front后右移；
 * 记录这条小的连续子数组length;
 * 不断推动front直到 nums sub(r)  :数组末尾位;
 * 取得最小的length，
 * */
// 动态调整窗口的起始位置
/* 定义： for i 作为front， 满足 sunSum >= target; 作为 长度较小 连续子数组
 * 初始移动： 当前窗口和值 >= target ，向前移动一格（缩小）；
 * 结束移动： i 到 sums.size(); （结尾）
 * */
class solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int arrLength = INT32_MAX;
        int subLength = 0;
        int subSum = 0;
        int numsInd = 0; // nums index 滑动窗口 **起始位置**
        for (int j = 0; j < nums.size(); ++j) {
            subSum += nums[j];
            while (subSum >= target)
            {
                subLength = (j - numsInd) + 1;  // rear - front + 1, 本次子序列长度
                arrLength = arrLength < subLength ? arrLength : subLength;
                subSum -= nums[numsInd++];  // 子序列和值范围缩小
            }
        }
        return arrLength == INT32_MAX ? 0 : arrLength;
    }
};


// 暴力姐姐： 两个for找到最小length
// 暴力递归方法
class force_Solu {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int arrLength = INT32_MAX; //最终长度最小
        int subLength = 0; //计算中的子序列长度
        int subSum = 0;    //计算中的数组之和值
        for (int i = 0; i < nums.size(); ++i) { // i == front
            subSum = 0; //每次都要重置计算中子序列和值
            for (int j = i; j < nums.size(); ++j) { //j == rear
                subSum += nums[j];  // 计算线性和值
                if(subSum >= target){   // 找到了条件
                    subLength = j - i +1;
                    arrLength = arrLength < subLength ? arrLength : subLength;  //若arr小则延续arr，否则代入subLength
                    break;  //进入下一轮 枚举
                }
            }
        }
        return arrLength < INT32_MAX ? arrLength : INT32_MAX;
    }
};



//
// Created by 陈至宇 on 2023/2/8.
//
