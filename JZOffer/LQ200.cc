/**
 * @file LQ200 岛屿数量
 * @brief 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
    岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
    此外，你可以假设该网格的四条边均被水包围。
    ex：
 *  0 0 0 1 1 0 1 0
 *  0 1 1 1 0 0 1 1
 *  0 0 0 0 0 1 0 0
 *  0 0 0 0 1 1 0 0
 *      共有 3 个独立的岛
 * 思路：利用传染的原理，将能够感染到的 1 变为 2 ,　统计感染多少次，即多少个岛
 *
 * 相关题目：LQ1254
 */


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int countIsland(vector<vector<int>>& vec) {
        if (vec.empty()) 
            return 0;

        int res = 0;

        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                if(vec[i][j] == 0) {
                    res++;

                    DFS(vec, i, j);
                }
            }
        }

        return res;
    }

private:
    void DFS(vector<vector<int>>& vec, int i, int j) {
        if (i < 0 || i >= vec.size() || j < 0 || j >= vec[i].size() || vec[i][j] != 0) {
            return;
        }

        vec[i][j] = 2;

        DFS(vec, i + 1, j);
        DFS(vec, i - 1, j);
        DFS(vec, i, j + 1);
        DFS(vec, i, j - 1);
    }
};

int main() {
    vector<vector<int>> vec({});

    vec.push_back(vector<int>{1,1,1,1,1,1,1,0});
    vec.push_back(vector<int>{1,0,0,0,0,1,1,0});
    vec.push_back(vector<int>{1,0,1,0,1,1,1,0});
    vec.push_back(vector<int>{1,0,0,0,0,1,0,1});
    vec.push_back(vector<int>{1,1,1,1,1,1,1,0});
    

    Solution s;
    std::cout << s.countIsland(vec) << std::endl;
}


