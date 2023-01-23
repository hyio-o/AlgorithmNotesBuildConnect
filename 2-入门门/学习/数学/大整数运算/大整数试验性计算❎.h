#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <time.h>

#define MAXN 9527

struct BigN {
    short int val[MAXN];
    int length;

    BigN() {
        memset(val, -1, sizeof(val));
        length = 0;
    }
};

void create_bigN(BigN &A) { // 需要保证末位不为0， 即头部
    A.length = 4;
    int seed;
    for (int i = 0; i < A.length; ++i) {
        seed = rand() % 10;
        if (i == 0 && seed == 0) {
            srand((unsigned) time(NULL));
            seed = rand() % 10;
            i--;
        } else
            A.val[i] = seed;
    }
}

BigN addFunc(BigN A, BigN B) {
    /*思路： 1。得到两者的最长len， 从尾到头相加
     * 2。 加： 进位 temp %10 /10*/
    int temp = 0, maxLen = 0, minLen = 0, i = A.length - 1, t = B.length - 1;
    int carry = 0;  // 进位
    BigN C;
    maxLen = (A.length < B.length) ? B.length : A.length;

    // 若
    while (maxLen > 0) {  // i=A.length-1, t=B.length-1
        if (i >= 0 && t >= 0) {
            temp = A.val[i--] + B.val[t--] + carry;
            C.val[C.length++] = temp % 10;
            carry = temp / 10;
        } else if (i >= 0 && t < 0)
            C.val[C.length++] = A.val[i--];
        else
            C.val[C.length++] = B.val[t--];
        printf("::%d == C.val[%d]::\n", C.val[C.length], i);
        maxLen--;
    }
    if (carry != 0)
        C.val[C.length++] = carry;

    return C;
}

BigN minusFunc(BigN A, BigN B) {

}


void visitFunc(BigN A, BigN B, BigN C) {
    printf("The two long list int plus result:\n\nA:");
    for (int i = 0; i < A.length; ++i) {
        printf("%d", A.val[i]);
    }
    printf("\nB:");
    for (int i = 0; i < B.length; ++i) {
        printf("%d", B.val[i]);
    }
    printf("\nresult:");
    for (int i = C.length - 1; i >= 0; --i) {
        printf("%d", C.val[i]);
    }
}

BigN concatAB(BigN A, BigN B) {
    BigN C;
    for (int i = 0; i < A.length; ++i) {
        C.val[C.length++] = A.val[i];
    }
    for (int j = 0; j < B.length; ++j) {
        C.val[C.length++] = B.val[j];
    }
    return C;
}
//
// Created by 陈至宇 on 2022/3/2.
//

