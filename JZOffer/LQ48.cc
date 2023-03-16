/**
 * @file LQ48 旋转图像
 * @brief 给定一个n×n的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转90度。
        你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。
        请不要使用另一个矩阵来旋转图像。

    链接：https://leetcode.cn/problems/rotate-image
 * 思路：两次翻转
    - 左右翻转
    - 以右上角至左下角为轴翻转
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;

        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        
        for (int i = 0; i <= m; i++ ){
            for(int j = 0; j <= n / 2; j++ ){
                swap(matrix[i][j], matrix[i][n - j]);
            }
        }

        for (int i = 0; i <= m; i++ ){
            for (int j = 0; j <= n - i; j++) {
                swap(matrix[i][j], matrix[m - j][n - i]);
            }
        }
    }
};