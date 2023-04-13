/**
 * @file JZ14- I. 剪绳子
 * @brief 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
    每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    链接：https://leetcode.cn/problems/jian-sheng-zi-lcof

    思路：判断 n 中有多少个3，并根据对3取余所得q的值，进行不同的运算：
        q = 0时，pow(3, p);
        q = 1时，pow(3, p -1 ) * 4; // 因为 3 * 1 < 2 * 2 = 4
        q = 2时，pow(3, p) * q;
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        
        if (n == 3)
            return 2;

        int p = n / 3;
        int q = n % 3;
        if (q == 0)
            return std::pow(3, p);
        else if (q == 1)
            return std::pow(3, p - 1) * 4;
        else
            return std::pow(3, p) * q;
    }
};

int main() {
    Solution s;
    for(int n = 2; n < 59; ++n) {
        std::cout << "n = " << n 
            << " Max: " << s.cuttingRope(n) << std::endl;
    }
}