/**
 * @file LQ123 买卖股票的最佳时机 III 
 * @brief 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
            设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
            注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii
 *  思路：动态规划
        d[i][0] 表示从第 0 天到第 i 天第一次买股票时的最大收益
        d[i][1] 表示从第 0 天到第 i 第一次卖股票时的最大收益
        d[i][2] 表示从第 0 天到第 i 第二次买股票时的最大收益
        d[i][3] 表示从第 0 天到第 i 第二次卖股票时的最大收益
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int n = prices.size();

        // 动态数组
        vector<vector<int>> dp(n, vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;

        // 状态转移
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        return dp[n - 1][3];
    }
};