/**
 * @file LQ322 零钱兑换
 * @brief
        给你一个整数数组coins，表示不同面额的硬币；以及一个整数amount，表示总金额。
        计算并返回可以凑成总金额所需的最少的硬币个数。
        如果没有任何一种硬币组合能组成总金额，返回 -1 。
        你可以认为每种硬币的数量是无限的。

    链接：https://leetcode.cn/problems/coin-change

    思路：完全背包
        注意事项：
            0-1背包：一维dp数组，需要先遍历物品，再遍历背包，且内层循环从大到小
            完全背包： 一维dp数组
                - 求组合数，先遍历物品，再遍历背包
                - 求排列数，先遍历背包，再遍历物品
                - 求最小数，先后遍历顺序无所谓
 */

#include <limits.h>

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> d(amount + 1, 0x3FFFFFFF);
        d[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto& coin : coins) {
                if (coin <= i) d[i] = min(d[i], d[i - coin] + 1);
            }
        }

        return d[amount] == 0x3FFFFFFF ? -1 : d[amount];
    }
};

int main() {
    Solution so;
    vector<int> coins{1, 2, 5};
    int amount = 3;
    cout << so.coinChange(coins, amount) << '\n';
}