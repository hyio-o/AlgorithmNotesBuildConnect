/*普通定义方式： 判断n是否能被 2，3，4，··，n-1中的一个整除*/
#include <cmath>

/*快速定义方式： 若2～n-1中存在n的约数， 设其为k， 存在n%k==0， 即由k*(n/k)==n❓,
 *  有n/k也是n的一个约数， 且k与n/k中一定满足其中一个小雨sqrt(n) 和 另一个大于 sqrt(n)
 *  意味着只要能被2,3,--，sqrt(n)向下取整就能判断素数*/
// 对n开根号， 再到达根号n
bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int) sqrt(1.0 * n);     //sqrt()要求浮点数， 即 1.0*n 使其成为
    for (int i = 2; i < sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// 法二，直接乘i， 当n方小于int型时候
bool isPrime_N(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
//
// Created by 陈至宇 on 2022/2/27.
//

