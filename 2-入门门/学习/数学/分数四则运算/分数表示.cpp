#include "../最大公约数.cpp"

struct Fraction {
    int numerator, denominator;
};
/*分数表述*/
// 使分母为非负整数， 分数为负则令分子为负
// 若分数为0， 规定分子为0， 分母为1
// 分子 分母 没有除了1之外当  公约数--使二者都为最简

/*分数化简*/
// TODO 若分母为负数， 则令 分子+分母都变为相反数
// 若分子为0 则令分母为1
// 约分：求分子绝对值 与 分母绝对值 最大公约数d， 且令分子 + 分母同时处以d
Fraction reduction(Fraction result) {    //分数化简⭐️
    if (result.denominator < 0) { //若分母为负数， 则令 分子+分母都变为相反数
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }
    if (result.numerator == 0)
        result.denominator = 1;
    else {
        int d = gcd_H(result.numerator, result.denominator);
        result.numerator /= d;
        result.denominator /= d;
    }
    return result;
}

//
// Created by 陈至宇 on 2022/2/26.
//

