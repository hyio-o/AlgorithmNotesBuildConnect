#include "分数四则运算.cpp"
#include <cstdio>
#include <cmath>

// 输出先化简
// 若分数 r 分母为1， 说明是整数->直接输出分子省略分母输出
// 若分数 r 分子绝对值大于分母（假分数）->按带分数形式输出：
// 整数·（分子/分母）：：整数abs(r.up)/r.down;
// 分数 分子：(abs(r.up)%r.down)；分母：r.down ||
// 取了abs且因其分母在reduction时候将负数转移到自身
// 最后一种情况是直接输出 真分数
void showResult(Fraction r) {
    r = reduction(r);
    if (r.denominator == 1)
        printf("%lld", r.numerator);    // 此分子分母相乘可能变成超级大都数超级大
    else if (abs(r.numerator) > r.denominator)
        printf("%d %d/%d", r.numerator / r.denominator,
               abs(r.numerator) % r.denominator, r.denominator);
    else
        printf("%d/%d", r.numerator, r.denominator);
}

//
// Created by 陈至宇 on 2022/2/27.
//

