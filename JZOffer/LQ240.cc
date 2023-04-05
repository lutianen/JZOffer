/**
 * @file LQ240 搜索二维矩阵 II
 * @brief 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target
    该矩阵具有以下特性：
        每行的元素从左到右升序排列。
        每列的元素从上到下升序排列。

    思路：利用矩阵特性，从左下角开始搜索
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] < target)
                j++;
            else if (matrix[i][j] > target)
                i--;
            else
                return true;
        }

        return false;
    }
};

int main() {
    /**
    Input:
        3 3 12
        1 4 8
        3 6 9
        10 12 14
    Output:
        1
     */
    int m, n, tar;
    cin >> m >> n >> tar;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution s;
    cout << s.searchMatrix(matrix, tar) << endl;

    return 0;
}