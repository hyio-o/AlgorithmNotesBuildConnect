// [+-] [1~9] [.] [0~9] E [+-] [0~9]
// 此题如果分步骤来做的话应该会方便输出
#include <cstdio>
#include <cstring>

void scientificCal() {
    char str[10010]; // 9999+10+1
    gets(str);
    int len = strlen(str);
    if (str[0] == '-') printf("-");

    int pos = 0;
    while (str[pos] != 'E') pos++;

    int exp = 0;
    for (int i = pos + 2; i < len; ++i) {
        exp = exp * 10 + (str[i] - '0');
    }
    if (exp == 0)
        for (int i = 1; i < pos; ++i) {
            printf("%c", str[i]);
        }
    else;

    if (str[pos + 1] == '-') {
        printf("0.");
        for (int i = 0; i < exp - 1; ++i) {
            printf("0");
        }
        printf("%c", str[1]);
        for (int i = 3; i < pos; ++i) {
            printf("%c", str[i]);
        }
    } else {

    }

}


//
// Created by 陈至宇 on 2022/3/30.
//

#ifndef ALGORITHMNOTESBUILDING_B1024_A1073_科学计数法_H
#define ALGORITHMNOTESBUILDING_B1024_A1073_科学计数法_H

#endif //ALGORITHMNOTESBUILDING_B1024_A1073_科学计数法_H
