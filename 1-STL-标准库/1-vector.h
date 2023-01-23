#include <vector>
using namespace std;

void initVec(vector<int> vec){
    // push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
    printf("vector size=%lu\n", vec.size());
    for (int i = 0; i < 5; ++i) {   // push
        vec.push_back(i);
    }
    printf("\nInitiating proc is all clear.\n");
}

// 1. define :: vector<typename> name;
struct node{
    int A[10];
    int len = 0;
};
vector<int> val;        // 基本类型
vector<node> my_node;       // 结构体
vector<vector<int>> container;  //容器， >> 要加空格再 container 命名变量
vector<int> A[10];

// 2. visit ：： 1⃣️下标访问 2⃣️迭代器访问
void visit(vector<int> A){
    initVec(A);
    // 1. A[i] == *(A.begin() + i)
    for (int i = 0; i < 5; ++i) {
        printf("::%d::\t", A[i]); // require|| visit
    }
    // 2.-- 迭代器 iterator ;;begin( ) 函数返回一个指向向量开头的迭代器。end( ) 函数返回一个指向向量末尾的迭代器
    vector<int>::iterator v = A.begin(); // 需要加空格🈳️
    while (v != A.end()){
        printf("value of v=%d, ptr=%p\n", *(v), &v);
        v++;
    }
}

// 3. auto
void autoVec(){
    vector<int> vec;
    printf("vector size=%lu\n", vec.size());
    for (int i = 0; i < 5; ++i) {   // push
        vec.push_back(i);
    }
    printf("vector size=%lu\n", vec.size());
    for (int i = 0; i < 5; ++i) {
        printf("::%d::\t", vec[i]); // require|| visit
    }

    // container -- 迭代器 iterator
    vector<int>::iterator v = vec.begin();
    while (v != vec.end()){
        printf("value of v=%d, ptr=%p\n", *(v), &v);
        v++;
    }
}


//
// Created by 陈至宇 on 2022/3/3.
//

