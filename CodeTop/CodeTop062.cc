/**
 * @file CodeTop062.cc
 *
 * @brief 最小路径和
 *  给定一个包含非负整数的 m x n 网格 grid
 *  请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *  说明：每次只能向下或者向右移动一步。
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        size_t m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m, vector<int>(n, 0));
        d[0][0] = grid[0][0];

        for (size_t i = 1; i < n; ++i) d[0][i] = d[0][i - 1] + grid[0][i];
        for (size_t i = 1; i < m; ++i) d[i][0] = d[i - 1][0] + grid[i][0];

        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                d[i][j] = grid[i][j] + min(d[i - 1][j], d[i][j - 1]);
            }
        }
        return d[m - 1][n - 1];
    }
};

int main() {
    // vector<vector<int>> nums{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}};
    Solution so;
    cout << so.minPathSum(nums) << endl;
    return 0;
}
