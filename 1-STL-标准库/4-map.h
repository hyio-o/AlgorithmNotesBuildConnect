/* map- 映射；； 将任何基本类型映射到任何基本类型 ：： string -> int
 * other vice：
 * 迭代器访问：  map<tp1, tp2>::iterator it;
 * 函数： find(it); erase(it) / erase(key) / erase(first, last); size(); clear()
 * */
#include <cstdio>
#include <map>
using namespace std;

map<char, int> my_map;
void dilute_map(){
    my_map['R'] = 20;
    map<char, int>::iterator it = my_map.begin();
    printf("%d -- %c", it->second, it->first);
}

//
// Created by 陈至宇 on 2022/3/8.
//

#ifndef ALGORITHMNOTESBUILDING_4_MAP_H
#define ALGORITHMNOTESBUILDING_4_MAP_H

#endif //ALGORITHMNOTESBUILDING_4_MAP_H
