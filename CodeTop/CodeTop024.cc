/**
 * @brief 最长递增子序列
 * @link https://leetcode.cn/problems/longest-increasing-subsequence
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        // d[i], 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> d(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    d[i] = std::max(d[i], d[j] + 1);
            }
        }

        return *std::max_element(d.begin(), d.end());
    }
};

int main () {
    vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    Solution so;
    std::cout << so.lengthOfLIS(nums) << std::endl;

    return 0;
}