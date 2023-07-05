//根据性别找最高低分 男生的最低分：姓名 学号  ，找 女生最高分
// 输入格式 姓名 学号 分数； 输出 按性别女->男牌序： 姓名 学号 以及最后一行差异分数abs
#include <cstdio>
#include <cstdlib>

struct student {
    char name[15];
    char identity[15];
    char gender;
    int score;
} *stus;

void BvsG() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s%c%s%d", stus[i].name, &stus[i].gender, stus[i].identity, &stus[i].score);
    }
    student M, F, temp;
    M.score = -1;
    F.score = -1;
    for (int i = 0; i < N; ++i) {
        if (stus[i].gender == 'F') {  //女
            if (F.score < stus[i].score)
                F = stus[i];
        } else if (stus[i].gender == 'M') {
            if (M.score < stus[i].score)
                M = stus[i];
        }
    }
    if (F.score == -1) {
        printf("\nNA");
        printf("\n%s %s", M.name, M.identity);
    }

    if (M.score == -1) {
        printf("\n%s %s", F.name, F.identity);
        printf("\nNA");
    }


}

void BvsG_N() {
    student M, F, temp;
    M.score = 101;  // 男小
    F.score = -1;   // 女大
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        printf("::i=%d::\tPlease enter val\n", i);
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.identity, &temp.score);
        if (temp.gender == 'M' && temp.score < M.score)  //男生，此分更低则赋予M
            M = temp;
        else if (temp.gender == 'F' && temp.score > F.score) //女生，分更高则赋予F
            F = temp;
    }
    if (F.score == -1)   // 无女
        printf("Absent\n");
    else printf("%s %s\n", F.name, F.identity);
    if (M.score == 101)  // 无男
        printf("Absent\n");
    else printf("%s %s\n", M.name, M.identity);
    if (F.score == -1 || M.score == 101) printf("NA\n");
    else printf("%d\n", F.score - M.score);
}



//
// Created by 陈至宇 on 2022/3/26.
//

#ifndef ALGORITHMNOTESBUILDING_A1036_BOYSVSGIRLS_H
#define ALGORITHMNOTESBUILDING_A1036_BOYSVSGIRLS_H

#endif //ALGORITHMNOTESBUILDING_A1036_BOYSVSGIRLS_H
