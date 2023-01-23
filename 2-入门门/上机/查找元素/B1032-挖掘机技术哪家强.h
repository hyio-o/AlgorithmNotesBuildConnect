// 思路： 使用结构体
#include <cstdio>
#include <cstdlib>
#include <time.h>

#define maxn 30

struct school {
    int score[maxn];
    int len = 0;
} *schools;
int count_school = 3;
int count_score = 2;

void initSchoolScore(school *mySchools) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < count_school; ++i) {    // 第i个学校，该学校第t个分数
        for (int j = 0; j < count_score; ++j) {
            //srand((unsigned ) time(NULL));
            mySchools[i].score[mySchools[i].len++] = rand() % 101;
        }
    }
}

void viewSchoolScore(school *mySchools) {
    for (int i = 0; i < count_school; ++i) {    // 第i个学校，该学校第t个分数
        for (int j = 0; j < count_score; ++j) {
            printf("mySch[%d].score[%d]=%d\t", i + 1, j + 1, mySchools[i].score[j]);
        }
        printf("\n");
    }
}

void maxSchoolScore(school *mySchools) {
    int maxScore = 0, maxSCH = 1;

}
//
// Created by 陈至宇 on 2022/3/21.
//

#ifndef ALGORITHMNOTESBUILDING_B1032_挖掘机技术哪家强_H
#define ALGORITHMNOTESBUILDING_B1032_挖掘机技术哪家强_H

#endif //ALGORITHMNOTESBUILDING_B1032_挖掘机技术哪家强_H