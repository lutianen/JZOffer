/**
 * @file JZ47 礼物的最大价值
 * @brief
        在一个m*n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0)
        你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角
        给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

    思路：动态规划
        dp[i][j], 表示以 grid[i][j] 为结尾时的所获取礼物的最大价值和
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    // 空间复杂度 O(1)
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 左上角
                if (i == 0 && j == 0) continue;
                // 第一行 -> 只能向下
                else if (i == 0)
                    grid[i][j] += grid[i][j - 1];
                // 第一列 -> 只能向右
                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                // 中间位置 -> 选择较大值
                else
                    grid[i][j] += grid[i - 1][j] < grid[i][j - 1]
                                      ? grid[i][j - 1]
                                      : grid[i - 1][j];
            }
        }

        return grid[m - 1][n - 1];
    }

    // 空间复杂度 O(mn)
    int maxValue2(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 2}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    std::cout << s.maxValue2(grid) << std::endl;
    std::cout << s.maxValue(grid) << std::endl;
}
