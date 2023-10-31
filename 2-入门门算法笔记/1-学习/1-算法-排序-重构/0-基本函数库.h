#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>


using namespace std;

#define maxn 10000
#define INF 10000000

int A[8] = {8, 3, 5, 1, 4, 2, 7, 6};
vector<int> nums_A(A, A+8);
char B[10] = {'E','E','G','M','R','A','C','E','R','T'};
int C[10] = {5,5,7,13,23,1,3,5,23,25};
vector<char> nums_B(B, B+10);
vector<int> nums_C(C, C+10);


typedef struct {
    int data[maxn]; // from 1 -> MMAXN
    int length;
} SqList;

void mySwap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
    return;
}



//
class ANSolution{
    // less exch isSorted main
public:
    bool less(vector<int> a, vector<int> b)
    {
        return a < b;
    }
    void exch(vector<int>& a, vector<int>& b)
    {   // equals fuc: swap(a,b);
        vector<int> temp = a;
        a = b;
        b = temp;
    }
    void swap_vector(vector<int>& a, vector<int>& b)
    {   // equals fuc: swap(a,b);
        vector<int> temp = a;
        a = b;
        b = temp;
    }
private:

};

//
// Created by 陈至宇 on 2022/5/7.
//

#ifndef ALGORITHMNOTESBUILDING_0_基本函数库_H
#define ALGORITHMNOTESBUILDING_0_基本函数库_H

#endif //ALGORITHMNOTESBUILDING_0_基本函数库_H
