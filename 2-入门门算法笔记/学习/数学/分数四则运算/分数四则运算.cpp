#include "分数表示.cpp"


//分数加法： 分母1*分母2； 分子1*分母2+分子2*分母1
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduction(result);   //返回结果分数， 且化简通过⭐️
}

// 分数乘法: 分母1*分母2 ； 分子1*分子2
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduction(result);
}

// 分数除法: 分子1*分母2； 分母1*分子1 ：： 保持顺序 分子/分母
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return reduction(result);
}
//
// Created by 陈至宇 on 2022/2/27.
//

