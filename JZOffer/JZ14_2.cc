/**
 * @file JZ14- II. 剪绳子 II
 * @brief 剪绳子 II
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m
 - 1] 。 请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
    2 =< n <= 1000： 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

    链接：https://leetcode.cn/problems/jian-sheng-zi-ii-lcof

    思路：贪心 + 快速幂【必须使用 long 类型，防止溢出】
 */

#include <iostream>

class Solution {
public:
    /// 利用 qPow 快速幂算法
    int cuttingRope(int n) {
        if (n == 2) return 1;

        if (n == 3) return 2;

        int p = n / 3;
        int q = n % 3;
        if (q == 0)
            return qPow2(3, p) % MOD;
        else if (q == 1)
            return (qPow2(3, p - 1) * 4) % MOD;
        else
            return qPow2(3, p) * q % MOD;
    }

    /// 贪心算法
    /// 及时取余防止溢出
    /// 利用了取余的性质：(a%M + b%M)%M = (a+b)%M
    int cuttingRope2(int n) {
        if (n < 4) return n - 1;

        long res = 1;
        while (n > 4) {
            res = (res * 3) % MOD;
            n -= 3;
        }

        if (n != 0) {
            res *= n;
            res = res % MOD;
        }

        return res;
    }

private:
    const static int MOD = 1e9 + 7;

    /**
     * @brief 快速幂取余
     * 利用循环操作每次把指数 b 问题降低至指数 b//2 问题，只许循环 log(N) 次
     */
    long qPow(long a, long b) {
        long res = 1;
        while (b != 0) {
            // b 是奇数
            if ((b & 1) != 0) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;  // b / 2
        }
        return res;
    }

    // 快速幂 - 递归实现
    long qPow2(long a, long b) {
        if (b == 0) return 1;

        if ((b & 1) == 1)
            return (a * qPow(a, b - 1)) % MOD;
        else {
            long temp = qPow(a, b >> 1) % MOD;
            return (temp * temp) % MOD;
        }
    }
};

int main() {
    Solution s;
    for (int n = 2; n < 1000; ++n) {
        std::cout << "n = " << n << " Max multi: " << s.cuttingRope(n) << std::endl;
    }
}