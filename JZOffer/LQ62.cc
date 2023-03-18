/**
 * @file LQ62 不同路径
 * @brief 一个机器人位于一个 m x n 网格的左上角
    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
    问总共有多少条不同的路径？

链接：https://leetcode.cn/problems/unique-paths
 */


#include <vector>

using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<long long> temp(n + 1, 0);
        vector<vector<long long>> dp(m + 1, temp);
        
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 0; i <= n; i++) dp[0][i] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
