/**
 * @file LQ461 汉明距离
 * @brief 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
        给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

    思路：
        1. 两个数字异或后，判断结果中 1 的个数，即二进制位不同的数量
        2. C/C++ 内置函数 __builtin_popcount()，用于统计二进制数中 1 的数量
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;

        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if ((temp & 1) == 1) cnt++;
            temp >>= 1;
        }

        return cnt;
    }

    // 
    int hamingDistance2(int x, int y) { return __builtin_popcount(x ^ y); }
};

int main() {
    Solution so;
    so.hammingDistance(1, 4);
}