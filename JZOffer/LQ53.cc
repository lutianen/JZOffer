/**
 * @file LQ53 最大子数组和
 * @brief 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
          子数组 是数组中的一个连续部分。 
 * @思路：动态规划
 */

#include <algorithm>
#include <stdio.h>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        if (nums.empty()) return ret;        

        int n = nums.size();
        // vector<int> d(n, 0);
        // d[0] = max(nums[0], 0);

        // 优化成只使用一个变量 p
        int p = max(nums[0], 0);
        ret = nums[0];

        for (int i = 1; i < n; ++i) {
            p = max(p + nums[i], nums[i]);
            ret = max(p, ret);

            // d[i] = max(d[i - 1] + nums[i], nums[i]);
            // ret = max(ret, d[i]);
        }

        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a;
    vector<int> nums;
    while (cin >> a) {
        nums.push_back(a);
    }
    
    Solution s;
    int ret = s.maxSubArray(nums);
    cout << ret << endl;
}