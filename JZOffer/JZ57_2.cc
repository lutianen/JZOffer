/**
 * @file JZ57_2 和为s的连续正数序列
 * @brief
        输入一个正整数target，输出所有和为target的连续正整数序列（至少含有两个数）
        序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 * 思路：滑动窗口
        重要性质是：窗口的左边界和右边界永远只能向右移动，而不能向左移动。
        这是为了保证滑动窗口的时间复杂度是O(n)。
        如果左右边界向左移动的话，这叫做“回溯”，算法的时间复杂度就可能不止 O(n)
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // 滑动窗口
    vector<vector<int>> findContinuousSequence(int target) {
        if (target <= 0) return {};

        int left = 1, right = 2, sum = left + right;
        vector<vector<int>> res;
        while (left < right) {
            if (sum < target) {
                right++;
                sum += right;
            } else if (sum > target) {
                sum -= left;
                left++;
            } else {
                vector<int> temp{};
                for (int i = left; i <= right; i++) {
                    temp.push_back(i);
                }

                res.push_back(temp);
                right++;
                sum += right;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution so;

    int tar;
    std::cin >> tar;

    auto ret = so.findContinuousSequence(tar);
    for (auto vec : ret) {
        for (auto e : vec) std::cout << e << " ";

        std::cout << std::endl;
    }
}