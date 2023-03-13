/**
 * @file JZ47 礼物的最大价值
 * @brief 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

    动态规划
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 左上角
                if (i == 0 && j == 0) continue;
                // 第一行 -> 只能向下
                else if (i == 0) grid[i][j] += grid[i][j - 1] ;
                // 第一列 -> 只能向右
                else if(j == 0) grid[i][j] += grid[i - 1][j];
                // 中间位置 -> 选择较大值
                else grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? 
                        grid[i][j - 1] : grid[i - 1][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 2},
        {1, 5, 1},
        {4, 2, 1}};

    Solution s;
    std::cout << s.maxValue(grid);
}