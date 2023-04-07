/**
 * @file LQ322 零钱兑换
 * @brief 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
    计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
    你可以认为每种硬币的数量是无限的。

    链接：https://leetcode.cn/problems/coin-change

    思路：完全背包
        注意事项：
            0 - 1 背包：一维 dp 数组，需要先遍历物品，再遍历背包，且内层循环从大到小
            完全背包： 一维 dp 数组
                - 求组合数，先遍历物品，再遍历背包
                - 求排列数，先遍历背包，再遍历物品
                - 求最小数，先后遍历顺序无所谓
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount  == 0) return 0;
        if (amount < 0) return -1;

        int Max = amount + 1;
        vector<int> d(amount + 1, Max);
        d[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i)
                    d[i] = min(d[i], d[i - coins[j]] + 1); 
            }
        }

        return d[amount] > amount ? -1 : d[amount];
    }
};

int main() {
    Solution so;
    vector<int> coins {1, 2, 5};
    int amount = 11;
    cout << so.coinChange(coins, amount) << '\n';
}