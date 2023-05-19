/**
 * @brief 最大子数组和
 * @link https://leetcode.cn/problems/maximum-subarray/
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // d[i] 表示以 i 为结尾的 nums[i] 的最大连续子数组的和
        int n = nums.size();
        if(n <= 0) return -1;
        if(n == 1) return nums[0];

        vector<int> d(n);
        d[0] = nums[0];
        int maxv = d[0];
        for (int i = 1; i < n; ++i) {
            d[i] = max(nums[i], d[i - 1] + nums[i]);
            maxv = max(maxv, d[i]);
        }

        return maxv;
    }
};

int main () {
    Solution so;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << so.maxSubArray(nums) << endl;

    return 0;
}