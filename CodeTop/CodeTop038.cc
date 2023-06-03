/**
 * @brief 爬楼梯
 * @link https://leetcode.cn/problems/climbing-stairs/
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;

        // d[i] 表示到达第 i 阶台阶的不同方法数量
        // d[i] = d[i - 1] + d[i - 2]
        vector<int> d(n + 1);
        d[1] = 1;
        d[2] = 2;

        for (int i = 3; i <= n; ++i) d[i] = d[i - 1] + d[i - 2];

        return d[n];
    }
};

int main() {
    Solution so;
    std::cout << so.climbStairs(4) << std::endl;
    return 0;
}