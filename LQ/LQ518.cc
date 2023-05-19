/**
 * @file LQ518 零钱兑换 II
 * @brief
 *      给你一个整数数组coins表示不同面额的硬币，另给一个整数amount表示总金额。
 *      请你计算并返回可以凑成总金额的硬币组合数。
 *      如果任何硬币组合都无法凑出总金额，返回0。
 *      假设每一种面额的硬币有无限个。
    思路：完全背包 - 组物排包
        子问题：选择 coin[j]时，总额为 i - coin[j] 的组合数
        状态数组：d[i] - 硬币总额为 i 时的方案组合数量；
        状态转移：d[i] = d[i] + d[i - coin[j]]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        // d[i] 表示硬币总额为 i 时的硬币组合数
        // d[i] = d[i - coin[j]] + d[i] -->> d[i] += d[i - coin[j]]
        vector<int> d(amount + 1, 0);
        d[0] = 1;

        // 组物 - 外层循环遍历物品 + 内层循环遍历背包
        for (int coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                d[j] += d[j - coin];
            }
        }

        return d[amount];
    }
};

int main(int argc, char* argv[]) {
    Solution so;
    int amount = 5;
    vector<int> coins{1, 2, 5};

    std::cout << so.change(amount, coins) << std::endl;
}
