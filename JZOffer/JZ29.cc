/**
 * @file JZ29 顺时针打印矩阵
 * @brief 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

    思路：每遍历一圈，则将表示本圈范围的变量缩小；
    并且每遍历一条边时，都需要判断是否已经打印完全（因为不知道会终止在那一条边）
 */

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) 
            return {};
        
        // Left Right Top Bottom
        int L = 0, R = matrix[0].size() - 1, T = 0, B = matrix.size() - 1;
        vector<int> result {};
        
        while(true) {
            // L -> R
            for (int i = T, j = L; j <= R; ++j)
                result.push_back(matrix[i][j]);
            if (++T > B)
                break;
            
            // T -> B
            for(int i = T, j = R; i <= B; ++i)
                result.push_back(matrix[i][j]);
            if (L > --R)
                break;

            // R -> L
            for(int i = B, j = R; j >= L; j--)
                result.push_back(matrix[i][j]);
            if (T > --B)
                break;

            // B -> T
            for(int i = B, j = L; i >= T; i--)
                result.push_back(matrix[i][j]);
            if (++L > R)
                break;
        }

        return result;
    }
};

int main() {
    vector<vector<int>> m {{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12}};

    Solution s;
    vector<int> ret = s.spiralOrder(m);

    for(auto& e : ret)
        std::cout << e << ' ';
}