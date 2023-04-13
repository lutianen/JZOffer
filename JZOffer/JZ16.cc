/**
 * @file JZ16 数值的整数次方
 * @brief 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）
    不得使用库函数，同时不需要考虑大数问题。

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    -104 <= xn <= 104

    核心：快速幂【防止溢出】
        首先将 n 转成 long long 类型的 N， 然后再取相反数【溢出】
        导致快速幂函数也要接收 long long 类型，不能是 int，否则报错
 */


#include <cmath>
#include <iostream>

static bool g_InvalidInput = false;

class Solution {
public:
    double myPow(double x, int n) {
        // 坑点：n为 int 类型时，-2147483648的相反数无法表示
        // 解决方法：首先将 n 转成 long long 类型的 N， 然后再取相反数 -->> 导致快速幂函数也要接收 long long 类型，不能是 int，否则报错
        
        // 当底数为 0，且指数小于 0 时，无意义
        if (n < 0 && (std::fabs(x - 0) < 0.0000001)) {
            g_InvalidInput = true;
            return 0.0;
        }
        
        long long N = n;
        if (N > 0)
            return quickPow(x, N);
        else
            return 1/quickPow(x, -N);
    }

private:
    double quickPow(double x, long long n) {
        if (n == 0) return 1;
        else if((n & 1) == 1)
            return myPow(x, n - 1) * x;
        else {
            // 利用中间变量，减少函数调用
            double temp = myPow(x, n >> 1);
            return temp * temp;
        }
    }
};

int main() {
    Solution s;
    std::cout << s.myPow(2.0, -2147483648) << std::endl;
}
