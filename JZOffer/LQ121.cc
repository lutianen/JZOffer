/**
 * @file LQ121 买卖股票的最佳时机
 * @brief 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
        你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
        返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

    链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock
 *  思路：动态规划
        d[i] 表示第 i 天所能获得的最大利润
        
        // 第 i 天进行股票卖出（p[i] - minp）或不卖(d[i - 1])的最大值为第 i 天的最大利润
        d[i] = max(d[i - 1], p[i] - minp);
        minp = min (minp, p[i]);
 */

#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> d(prices.size());
        d[0] = 0;
        int minp = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            d[i] = max(d[i - 1], prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        return d[prices.size() - 1];
    }
};
