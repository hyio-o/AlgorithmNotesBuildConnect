#include <cstring>

// 使用数组存储， 整数高位存储在数组的高位， 低位在数组的低位。顺序
// 运算时
struct BigNum {
    int d[1000] = {0};
    int len = 0;
};

// 自动初始化结构体变量
struct bign {
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

// 倒叙输出 str数组
bign change(char str[]) {
    bign val;
    val.len = strlen(str);
    for (int i = 0; i < val.len; ++i) {
        // val.len-i-1 实际地址长
        val.d[i] = str[val.len - i - 1] - '0';
    }
    return val;
}

int compare(bign a, bign b) {
    if (a.len > b.len) return 1; // a更长/大
    else if (a.len < b.len) return -1;
    else {   //等长
        for (int i = a.len - 1; i >= 0; --i) {    // 从高位到低位比较
            if (a.d[i] > b.d[i]) return 1;   // a更长/大
            else if (a.d[i] < b.d[i]) return -1;
        }
        return 0; // 完全相等
    }
}


//
// Created by 陈至宇 on 2022/3/2.
//

