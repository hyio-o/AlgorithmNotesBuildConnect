
//
// Created by 陈至宇 on 2022/2/22.
//

// 输入字符串， 倒叙， 输出
// 1。 gets 读入整行， 左右枚举空格为分；存储二维字符数组，按单词输入顺序逆序输出
#include <cstdio>

#define MAXLEN 100

int inputLine(char **line) {
    char temp_voice;
    int row = 0, col = 0;
    while (row < MAXLEN && col < MAXLEN) {
        scanf("%c", &temp_voice);
        col++;
        if (temp_voice == ' ')
            row++;
    }
    return --row;
}

void outputUpSetLine(char **line) {
    int row = inputLine(line);
    while (row >= 0) {
        int col = 0;
        while (line[row][col] != '\0') {
            printf("%c", line[row][col]);
            col++;
        }
        printf("  ");
    }
}


int main() {
    char **myline;
    outputUpSetLine(myline);
    return 0;
}
