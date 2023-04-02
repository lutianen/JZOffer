/**
 * @file LQ122 买卖股票的最佳时机 II
 * @brief 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
        在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
        返回 你能获得的 最大 利润 。

    链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
 *  思路：贪心 / 动态规划
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int temp = prices[i] - prices[i - 1];
            profit += temp > 0 ? temp : 0;
        }

        return profit;
    }


    /**
     * @brief d[i][0] - 表示第 i 天持有现金时的最大收益
     *        d[i][1] - 表示第 i 天持有股票时的最大收益 
     * @param prices 
     * @return int 
     */
    int dp(vector<int>& prices) {
        if (prices.empty())
            return 0;
        
        auto n = prices.size();
        vector<vector<int>> d(n, vector<int>(2));

        d[0][0] = 0;
        d[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            d[i][0] = max(d[i - 1][0], d[i - 1][1] + prices[i]);
            d[i][1] = max(d[i - 1][1], d[i - 1][0] - prices[i]);
        }

        return d[n - 1][0];
    }


    /**
     * @brief 使用有限个滚动数组进行优化
     *      d[0] 表示持有现金时的最大收益
     *      d[1] 表示持有股票时的最大收益
     * @param prices 
     * @return int 
     */
    int dp2(vector<int>& prices) {
        if (prices.empty())
            return 0;

        auto n = prices.size();
        vector<int> d(2, 0);
        d[0] = 0;
        d[1] = -prices[0];

        for (int i = 1; i < n; i++) {
            int temp1 = max(d[0], d[1] + prices[i]);
            int temp2 = max(d[1], d[0] - prices[i]);

            d[0] = temp1;
            d[1] = temp2;
        }

        return d[0];
    }
};
