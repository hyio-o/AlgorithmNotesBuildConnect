// 是故才德全尽谓之圣人,才德兼亡谓之愚人,德胜才谓之君子,
// 才胜德谓之小人。凡取人之术,苟不得圣天,君子而与之,与其得小人,不若得愚人”
// 第一行 三个整数： N考生总数 L录取最低分数线 H优先录取线
// H：才德兼备 ：：总分 从高到低排序 flag=1
// 才❌德✅ 德胜才为君子 ， 总分 * flag=2
// 德&才<H , 但 德>才 ：：才德兼亡， 德胜才 flag=3
// 在L之上 ：： 总分  else， flag=4
// 有一个在L之下 ： 不及格 flag=5
/* 思路： 学生数 最低录取 最高录取； 学号 德分D 才分C :: 总分 sum = C+D
 * 定义结构体， 在结构体中排序；
 * */
#include <cstdio>
#include <cstring>

#define maxn 1000


struct student {
    char id[10];
    int D, C, sum;
    int flag;
} stus[maxn];

// 预处理 考生总分sum， 类别， 合格人数
bool cmp(student a, student b) {
    if (a.flag != b.flag) return a.flag < b.flag;  // 类别小的在前面
    else if (a.sum != b.sum) return a.sum > b.sum; // 类别相同，总分大在前
    else if (a.D != b.D) return a.D > b.D;     // 总分相同， 德大在前
    else return strcmp(a.id, b.id) < 0;   // 德相同，准考证小在前
}

void DC_discussion() {
    int n, L, H;
    scanf("%d %d %d", &n, &L, &H);
    int m = n;    // 及格人数
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", stus[i].id, &stus[i].D, &stus[i].C);
        stus[i].sum = stus[i].D + stus[i].C;
        if (stus[i].D < L || stus[i].C < L) {
            stus[i].flag = 5;
            m--;    // 及格人数--；
        }  // flag=5
        else if (stus[i].D >= H && stus[i].C >= H) stus[i].flag = 1;
        else if (stus[i].D >= H && stus[i].C < H) stus[i].flag = 2;
        else if (stus[i].D >= stus[i].C) stus[i].flag = 3;
        else stus[i].flag = 4;
    }// end for
    sort(stus, stus + n, cmp);
}

//
// Created by 陈至宇 on 2022/4/4.
//

#ifndef ALGORITHMNOTESBUILDING_B1015_德才论_H
#define ALGORITHMNOTESBUILDING_B1015_德才论_H

#endif //ALGORITHMNOTESBUILDING_B1015_德才论_H
