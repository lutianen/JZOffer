/**
 * @file LQ70 爬楼梯
 * @brief 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
        每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

    思路：DP
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> d(n + 1, 0);
        d[1] = 1;
        d[2] = 2;
        for (int i = 3; i <= n; ++i) d[i] = d[i - 1] + d[i - 2];
        return d[n];
    }
};

int main() {
    Solution so;
    std::cout << so.climbStairs(3) << std::endl;
}