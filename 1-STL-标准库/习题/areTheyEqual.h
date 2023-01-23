/* 1. find dot sig, 失败返回 -1， 那么可以直接从头到尾 begin_TO_end;; 将值传递给Slen1，Slen2；比较长度，
 * 2.
 * */
#include <cstdio>
#include <cstring>
#include <string>

#include "../3-string.h"

void areTheyEQ() {
    int reserve_num, Slen1 = 0, Slen2 = 0;
    char temp;
    string str1, str2, out_str1, out_str2;
    scanf("%d %s %s", &reserve_num, &str1, &str2);
    Slen1 = str1.length();
    Slen2 = str2.length();
    for (int i = 0, x = 0, y = 0; i < reserve_num; ++i) {
        if (str1[i] != '.' && str1[i] != '\0')
            out_str1[x++] = str1[i];
        if (str2[i] != '.' && str1[i] != '\0')
            out_str2[y++] = str2[i];
    }
    // compare

    printf("\n%s\n%s", &out_str1, &out_str2);
}


//
// Created by 陈至宇 on 2022/3/7.
//

#ifndef ALGORITHMNOTESBUILDING_ARETHEYEQUAL_H
#define ALGORITHMNOTESBUILDING_ARETHEYEQUAL_H

#endif //ALGORITHMNOTESBUILDING_ARETHEYEQUAL_H
