/*思路：
 * 公共后缀，可以逆置为公共前缀，从头开始比较（并且是所输入的所有串中的公共部分）
 * 如果不存在公共后缀，则输出 "nai"
 * 先求出所有字符串的最小长度minLen[]，再枚举所有字符串在[0,minLen)内的字符
 * */
#include <cstdio>
#include <cstring>

void kuchigues() {
    char str_gets[110][260];
    int n, minLen = 256, ans = 0;

    scanf("%d", &n);    // n条字符串
    getchar();          // 接收换行符，而
    for (int i = 0; i < n; ++i) {
        gets(str_gets[i]);
        int len = strlen(str_gets[i]);
        if (len < minLen) minLen = len;    // gets min len
        for (int j = 0; j < len / 2; ++j) {     // 反转字符串
            char temp = str_gets[i][j]; // exchange
            str_gets[i][j] = str_gets[i][len - j - 1];
            str_gets[i][len - j - 1] = temp;
        }   // minLen 的作用，在于判断所有字符串序列中最短的是多长；
    }

    // judge
    for (int i = 0; i < minLen; ++i) {
        char c = str_gets[0][i];
        bool same = true;
        for (int j = 0; j < n; ++j) {   // 判断其余字符串的第i个字符是否都等于c
            if (c != str_gets[j][i]) {
                same = false;
                break;
            }
        }
        if (same) ans++;     // 存在相等的字符串公共长度；
        else break;
    }

    if (ans) {
        for (int i = ans - 1; i >= 0; --i) {
            printf("%c ", str_gets[0][i]);
        }
    } else
        printf("nai");
}

void exchange(char *str, int len) {
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}



//
// Created by 陈至宇 on 2022/4/3.
//

#ifndef ALGORITHMNOTESBUILDING_A1077_KUCHIGUES_公共字符串匹配_H
#define ALGORITHMNOTESBUILDING_A1077_KUCHIGUES_公共字符串匹配_H

#endif //ALGORITHMNOTESBUILDING_A1077_KUCHIGUES_公共字符串匹配_H
