#include <cstdlib>
#include <cstdio>
#include <time.h>
void createRandNum()
{
    // rand()
    int n = 10;
    for (int i = 0; i < n; ++i) {
        printf("::%d::\t", (rand()%10));
    }
    // srand() -- process seed::
    srand((unsigned )time(NULL));
    printf("\n\n");
    for (int i = 0; i < n; ++i) {
        printf("::%d::\t", (rand()%100));
    }
}


//
// Created by 陈至宇 on 2022/3/16.
//

#ifndef ALGORITHMNOTESBUILDING_RAND_FUNCTION_H
#define ALGORITHMNOTESBUILDING_RAND_FUNCTION_H

#endif //ALGORITHMNOTESBUILDING_RAND_FUNCTION_H
