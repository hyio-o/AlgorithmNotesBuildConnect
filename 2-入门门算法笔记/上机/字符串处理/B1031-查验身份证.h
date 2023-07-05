// 17位地区、日期编号 + 顺序编号 + 一位校验码
// 前17位数字加权求和, 权重{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}
// 计算上和，对11取模得到Z值； 再按照对应关系与校验码相呼应
// 0~10 : 1 0 X 9 8 7 6 5 4 3 2
// 输出有问题对号码
#include <cstdio>
#include <string>

void idIdentify() {
    char rectFy[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int power[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char testify[][] = {{"320124198808Z40056"},
                        {"1201OX198901011234"},
                        {"110108196711301866"},
                        {"370704198812i600IX"}
    };   // ad 0~16
    int r = 0, w = 0;

}



//
// Created by 陈至宇 on 2022/3/29.
//

#ifndef ALGORITHMNOTESBUILDING_B1031_查验身份证_H
#define ALGORITHMNOTESBUILDING_B1031_查验身份证_H

#endif //ALGORITHMNOTESBUILDING_B1031_查验身份证_H
