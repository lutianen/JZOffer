/**
 * @file LQ64 最小路径和
 * @brief 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
        说明：每次只能向下或者向右移动一步。
 * 
 */

#include <vector>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m, vector<int>(n));
        d[0][0] = grid[0][0];

        for(int i = 1; i < m; i++) 
            d[i][0] = d[i - 1][0] + grid[i][0];
        for(int i = 1; i < n; i++) 
            d[0][i] = d[0][i - 1]  + grid[0][i];;
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; i++) {
                d[i][j] = min(d[i][j - 1], d[i - 1][j]) + grid[i][j];
            }
        }

        return d[m - 1][n - 1];
    }
};

