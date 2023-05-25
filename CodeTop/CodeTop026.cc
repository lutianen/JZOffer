/**
 * @brief 接雨水
 * @link https://leetcode.cn/problems/trapping-rain-water/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        // perfix[i]，表示比 height[0 ... i] 中最高的，即前缀最大值
        // suffix[i]，表示比 height[i ... n-1] 中最高的，即后缀最大值
        vector<int> prefix(n);
        vector<int> suffix(n);

        // 求解前缀最大值、后缀最大值
        int temp = INT_MIN;
        for (int i = 0; i < n; ++i) {
            temp = std::max(temp, height[i]);
            prefix[i] = temp;
        }
        temp = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            temp = std::max(temp, height[i]);
            suffix[i] = temp;
        }

        // 根据前缀最大值、后缀最大值以及当前柱子高度，求解当前列所能接取的雨水
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += (std::min(prefix[i], suffix[i]) - height[i]);

        return sum;
    }
};

int main() {
    vector<int> height{4, 2, 0, 3, 2, 5};
    Solution so;
    std::cout << so.trap(height) << std::endl;
    return 0;
}