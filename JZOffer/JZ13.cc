/**
 * @file JZ13 机器人的运动范围
 * @brief 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
    它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
    例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
    请问该机器人能够到达多少个格子？

    链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof

    思路：DFS
 */


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


using std::vector;
using std::string;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m < 0 || n < 0 || k < 0)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        int cnt = 0;
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if(visited[i][j] == false)
                    DFS(m, n, 0, 0, k, cnt, visited);
            // }
        // }

        return cnt;
    }

    void DFS(int m, int n, int i, int j, int target, int& cnt, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || 
            j < 0 || j >= n || 
            helper(i, j) > target || visited[i][j])
            return ;
        
        cnt++;
        visited[i][j] = true;

        DFS(m, n, i - 1, j, target, cnt, visited);
        DFS(m, n, i + 1, j, target, cnt, visited);
        DFS(m, n, i, j - 1, target, cnt, visited);
        DFS(m, n, i, j + 1, target, cnt, visited);
    }

    int helper(int x, int y) {
        string str = std::to_string(x) + std::to_string(y);

        int sum = 0;
        for (auto e : str)
            sum += e - '0';

        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.helper(12, 2) << std::endl;
    std::cout << s.movingCount(3, 2, 1) << std::endl;
}

