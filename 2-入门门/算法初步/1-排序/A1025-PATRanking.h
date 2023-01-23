// N：测试点数量； Ki：每个考场的  考生号(13位) + 总分数(0~100)
// 排序后输出： 第一行为 总考生数量；
// 其后为 考生号 总排名 考场号 考场排名
/*思路：定义一个结构体，记录各个考场的 准考证号、排名、考场号、考场内排名
 * 排序方法，可以选择  插入排序
 * */
// 根据排名：总排名 考场内排名 ， 同排名时按考场号，输出
#include <cstdio>
#include <cstring>
#include <algorithm>

struct stu {
    char id[15];
    int score;
    int location_num;
    int local_rank;
} *stus;


bool cmp(stu a, stu b) {
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;   // str compare, len(a) - len(b);
    //TODO 此 return 意味着：
}

//
// Created by 陈至宇 on 2022/4/11.
//

#ifndef ALGORITHMNOTESBUILDING_A1025_PATRANKING_H
#define ALGORITHMNOTESBUILDING_A1025_PATRANKING_H

#endif //ALGORITHMNOTESBUILDING_A1025_PATRANKING_H
