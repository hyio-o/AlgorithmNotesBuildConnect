#include <set>
#include <cstdio>

using namespace std;

/*集合：： 内部自动有序， 不包含重复元素的容器 --- 加入set之后自动排序*/
// 1。 define set<typename> name;
set<int> my_int;
set<char> my_char[100]; // 每一个 my_char[i] 都是一个set容器
// set 容器 内元素访问 iterator
set<char>::iterator my_ite;

void print_set() {
    set<int> st;
    for (int i = 0; i < 500; ++i) {
        st.insert(i % 10);
    }
    st.erase(st.find(3));
    for (set<int>::iterator ite = st.begin(); ite != st.end(); ite++) {
        printf("::%d:: %p\t", *ite, &ite);
    }

    set<int>::iterator my_it = st.find(30000);
    printf("\n\nThere is my iterator val: %d", *my_it);
    printf("\n%d\n", *(st.find(30000)));
}
//
// Created by 陈至宇 on 2022/3/4.
//

#ifndef ALGORITHMNOTESBUILDING_2_SET_H
#define ALGORITHMNOTESBUILDING_2_SET_H

#endif //ALGORITHMNOTESBUILDING_2_SET_H
