/**
 * @brief 岛屿数量
 * @link https://leetcode.cn/problems/number-of-islands/
 */

#include <iostream>
#include <functional>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int cnt = 0;
        std::function<void (int, int)> dfs = [&] (int x, int y) {
            if (x < 0 || x >= grid.size() ||
                y < 0 || y >= grid[x].size() ||
                grid[x][y] != '1') {
                return;
            }
            
            grid[x][y] = '*';
            dfs(x - 1, y);
            dfs(x + 1, y);
            dfs(x, y - 1);
            dfs(x, y + 1);
        };

        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        return cnt;
    }
};

int main () {
    // vector<vector<char>> grid {
    //     {'1', '1', '0', '0', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '1', '0', '0'},
    //     {'0', '0', '0', '1', '1'}};

    vector<vector<char>> grid {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'0', '1', '0'}};

    Solution so;
    cout << so.numIslands(grid) << endl;
}