/**
 * @file JZ10_II 青蛙跳台阶问题
 * @brief 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
        答案需要取模 1e9+7
 *  思路：DP
        d[i] - 跳到 i 阶有 d[i] 种跳法
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const static int MOD = 1e9 + 7;

public:
    int numWays(int n) {
        if (n < 2) return 1;

        vector<int> d(n + 1);
        d[0] = 1;
        d[1] = 1;

        // d[i] = d[i - 1] + d[i - 2]
        for (int i = 2; i <= n; ++i) {
            d[i] = d[i - 1] + d[i - 2];
            d[i] %= MOD;
        }

        return d[n];
    }

    // 滚动数组
    int numWays2(int n) {
        if (n < 2) return 1;

        vector<int> d(2, 1);

        for (int i = 2; i <= n; i++) {
            int temp = d[0] + d[1];
            d[0] = d[1];
            d[1] = temp % MOD;
        }

        return d[1];
    }
};

int main() {
    int n;
    std::cin >> n;

    Solution so;
    std::cout << so.numWays(n) << std::endl;
    std::cout << so.numWays2(n) << std::endl;
}
