// 题：超长整型A+B相加，再比较C
//法一： 计算没精度的：
// 溢出：1⃣️两正 2⃣️两负 ； 正变负， 负变正  --> 探测则可比较C
// 不溢出： 1⃣️一正一负
bool nonePrecision(long long A, long long B, long long C) {
    long long temp = 0;
    if (A > 0 && B > 0) {
        temp = A + B;
        if (temp < 0) {  //发生溢出
            if (C > 0)
                return false;   //C small
            else
                return true;
        }
    }
}

// 法二：计算有精度， 超长整型计算
//
// Created by 陈至宇 on 2022/3/20.
//

#ifndef ALGORITHMNOTESBUILDING_A1065_A_BANDC_H
#define ALGORITHMNOTESBUILDING_A1065_A_BANDC_H

#endif //ALGORITHMNOTESBUILDING_A1065_A_BANDC_H
