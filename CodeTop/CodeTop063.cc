/**
 * @file CodeTop063.cc
 *
 * @brief 旋转图像
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;

        size_t m = matrix.size(), n = matrix[0].size();

        // 对角折叠
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution so;
    so.rotate(matrix);

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}