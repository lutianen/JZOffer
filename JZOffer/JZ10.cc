/**
 * @brief JZ10 - I. 斐波那契数列
        F(0) = 0,   F(1) = 1
        F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
        答案需要取模 1e9+7

    思路：DP / 滚动数组
 */

#include <iostream>

class Solution {
    const static int MOD = 1e9 + 7;

public:
    int fib(int n) {
        if (n < 2) return n;

        unsigned long long ans[n + 1];
        ans[0] = 0;
        ans[1] = 1;

        for (int i = 2; i <= n; ++i) {
            ans[i] = ans[i - 1] + ans[i - 2];
            ans[i] %= MOD;
        }

        return ans[n];
    }

    // 滚动数组
    int fib2(int n) {
        if (n < 2) return n;

        int ans[2];
        ans[0] = 0;
        ans[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int temp = ans[1] + ans[0];
            ans[0] = ans[1];
            ans[1] = temp % MOD;
        }

        return ans[1];
    }
};

int main() {
    Solution s;

    int num;
    std::cin >> num;

    std::cout << s.fib(num) << std::endl;
    std::cout << s.fib2(num) << std::endl;
}