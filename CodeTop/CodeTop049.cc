/**
 * @brief 零钱兑换
 * @link https://leetcode.cn/problems/coin-change/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        // d[i] 表示装满容量为 i 的背包，所需的最少硬币数量
        // d[i] = d[i - coins[j]] + 1;
        // NOTE 由于 amount + 1 是不可能达到的换取数量，故使其填充
        vector<int> d(amount + 1, amount + 1);
        d[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int j = coins.size() - 1; j >= 0; --j) {
                if (coins[j] <= i) d[i] = min(d[i], d[i - coins[j]] + 1);
            }
        }

        return d[amount] == amount + 1 ? -1 : d[amount];
    }
};

int main() {
    Solution so;
    // vector<int> coins{1, 2, 5};
    // int amount = 11;
    vector<int> coins{2};
    int amount = 3;
    std::cout << so.coinChange(coins, amount) << std::endl;
}