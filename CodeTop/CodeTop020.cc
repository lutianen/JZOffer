/**
 * @brief 螺旋矩阵
 * @link https://leetcode.cn/problems/spiral-matrix/
 */

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        vector<int> ret {}; 
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while(true) {
            // top
            for (int i = top, j = left; j <= right;){
                ret.push_back(matrix[i][j++]);
                if (j > right) {
                    top++;
                    break;
                }
            }
            if (top > bot) break;

            // right
            for (int i = top, j = right; i <= bot;) {
                ret.push_back(matrix[i++][j]);
                if (i > bot) {
                    right--;
                    break;
                }
            }
            if (left > right) break;

            // bottom
            for (int i = bot, j = right; j >= left;) {
                ret.push_back(matrix[i][j--]);
                if (j < left) {
                    bot--;
                    break;
                }
            }
            if (top > bot) break;

            // left
            for (int i = bot, j = left; i >= top;) {
                ret.push_back(matrix[i--][j]);
                if (i < top) {
                    left++;
                    break;
                }
            }
            if (left > right) break;
       } 

       return ret;
    }
};

int main () {
    vector<vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution so;
    auto ret = so.spiralOrder(matrix);
    for (const int e : ret) 
        cout << e << ", ";
    
    cout << endl;
    return 0;
}