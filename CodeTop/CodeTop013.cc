/**
 * @brief 买卖股票的最佳时机
 * @link https://leetcode.cn/problems/best-time-to-buy-and-sell-stock
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if (prices.empty()) return 0;

       int n = prices.size(), minv = prices[0];
       vector<int> d(n);
       d[0] = 0;
       for (int i = 1; i < n; ++i) {
            d[i] = max(d[i - 1], prices[i] - minv);
            minv = min(minv, prices[i]);
       }

       return d[n - 1];
    } 
};


int main() {
    vector<int> prices {7, 1, 5, 3, 6, 4};
    Solution so;
    cout << so.maxProfit(prices) << endl;

    return 0;
}
