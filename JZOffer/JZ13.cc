/**
 * @file JZ13 机器人的运动范围
 * @brief 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
    它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
    例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
    请问该机器人能够到达多少个格子？

    链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof

    思路：DFS + visited[i][j]
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;

        DFS(0, 0, k, cnt, visited);

        return cnt;
    }

private:
    int bitSum(int i) {
        int s = 0;
        while (i) {
            s += (i % 10);
            i /= 10;
        }

        return s;
    }
    int isValid(int i, int j, int k) { return (bitSum(i) + bitSum(j)) <= k; }

    int isValid2(int i, int j, int k) {
        // string iStr = std::to_string(i), jStr = std::to_string(j);

        // int sum = 0;
        // for (const auto c : iStr) sum += (c - '0');
        // for (const auto c : jStr) sum += (c - '0');

        // return sum <= k;

        string bitStr = std::to_string(i) + std::to_string(j);
        int sum = 0;
        for (const auto c : bitStr) sum += (c - '0');
        return sum <= k;
    }

    void DFS(int i, int j, int k, int& cnt, vector<vector<bool>>& visited) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[i].size() || visited[i][j] || !isValid2(i, j, k))
            return;

        visited[i][j] = true;
        cnt++;

        DFS(i + 1, j, k, cnt, visited);
        DFS(i - 1, j, k, cnt, visited);
        DFS(i, j - 1, k, cnt, visited);
        DFS(i, j + 1, k, cnt, visited);
    }
};

int main() {
    Solution s;
    std::cout << s.movingCount(3, 2, 1) << std::endl;
}
