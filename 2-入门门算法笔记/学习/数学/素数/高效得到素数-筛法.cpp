/*5-算法代码随想录： 从小到大枚举所有数， ❓对每一个素数筛去它的所有倍数就剩下了素数；❓
 * 若一开始不知道哪一些是素数：：判断后面的数字若没有被前面的数字所筛去，就？是？素数
 *
 * */
void Find_Prime(int &A) {
    const int MAXN = 101;
    int prime[MAXN], pNum = 0;
    bool p[MAXN] = {0};
    for (int i = 2; i < MAXN; ++i) {    // i为从1到万的整体检查
        if (p[i] == true) {
            prime[pNum++] = i;
            for (int j = 2 * i; j < MAXN; j += i)   // j 从2i开始， 就是 2i，3i， 4i 的递增序列
                p[j] = false;
        }
    }
}


//
// Created by 陈至宇 on 2022/3/1.
//

