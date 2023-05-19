/**
 * @file LZ63 股票的最大利润
 * @brief 假设把某股票的价格按照时间先后顺序存储在数组中
        请问买卖该股票一次可能获得的最大利润是多少?
 *  思路：
        1. 贪心算法
            记录最小价格，然后寻找最大差价，即为最大利润
        2. DP
            d[i] 表示第 i 天所能获得的最大利润
            d[i] = max{d[i - 1], prices[i] - cost};
            cost = min{cost, prices[i]};
 */

#include <cmath>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minprice = prices[0];
        int profit = 0;

        for (size_t i = 1; i < prices.size(); i++) {
            profit = std::max(profit, prices[i] - minprice);
            minprice = std::min(minprice, prices[i]);
        }

        return profit;
    }

    int maxProfit_DP(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        // d[i] 表示第 i 天卖出所获得的最大利润
        vector<int> d(n, 0);
        int cost = prices[0];
        for (int i = 1; i < n; ++i) {
            d[i] = std::max(d[i - 1], prices[i] - cost);
            cost = std::min(cost, prices[i]);
        }

        return d[n - 1];
    }
};

int main(int argc, char* argv[]) {
    Solution so;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    std::cout << so.maxProfit(prices) << std::endl;
}