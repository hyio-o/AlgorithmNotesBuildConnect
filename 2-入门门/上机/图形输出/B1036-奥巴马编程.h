// 输入数字+字符， 打印相应空方块
#include <cstdio>

void square() {
    int N;
    char c;
    scanf("%d %c", &N, &c);
    // n列 2*n 行
    for (int i = 1; i <= N; ++i) {
        printf("\n");
        if (i == 1 || i == N) {
            //printf("\n");
            for (int t = 1; t <= 2 * N; t++)
                printf("%c", c);
            //printf("\n");
        } else {
            //printf("\n");
            for (int j = 1; j <= N * 2; ++j) {
                if (j == 1 || j == N * 2)
                    printf("%c", c);
                else
                    printf(" ");
            }
            //printf("\n");
        }
        //printf("\n");
    }
}



//
// Created by 陈至宇 on 2022/3/26.
//

#ifndef ALGORITHMNOTESBUILDING_B1036_奥巴马编程_H
#define ALGORITHMNOTESBUILDING_B1036_奥巴马编程_H

#endif //ALGORITHMNOTESBUILDING_B1036_奥巴马编程_H
