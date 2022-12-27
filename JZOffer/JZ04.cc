/**
 * @brief 剑指 Offer 04. 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

#include <iostream>
#include <vector>

#include <ctime>

using namespace std;

class Solution {
public:

    /**
     * @brief 思路：利用矩阵从左到右、从上到下 非递减 的规律，从左下角开始查找，最多找 m * n 次：
        - matrix[i][j] < target 则向右找
        - matrix[i][j] > target 则向上找
        - matrix[i][j] == target 找到，返回 true
        - i/j 超界，则数组中不能存在目标数字，返回 false
     */
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
      return false;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int i = m - 1;
    int j = 0;
    for (int k = 0; k < m * n; ++k) {
      if (i < 0 || j >= n)
        return false;

      if (matrix[i][j] < target) {
        j++;
      } else if (matrix[i][j] > target) {
        i--;
      } else if (matrix[i][j] == target) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  Solution mySo;

  auto t = clock();
  std::cout << mySo.findNumberIn2DArray(matrix, 24) << std::endl;
  std::cout << mySo.findNumberIn2DArray(matrix, 12) << std::endl;
  std::cout << mySo.findNumberIn2DArray(matrix, 2) << std::endl;
  std::cout << mySo.findNumberIn2DArray(matrix, 21) << std::endl;
  std::cout << mySo.findNumberIn2DArray(matrix, 92) << std::endl;
  std::cout << mySo.findNumberIn2DArray(matrix, 82) << std::endl;

  cout << static_cast<float>(clock() - t) / CLOCKS_PER_SEC << " seconds."
       << endl;
}