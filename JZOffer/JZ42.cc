/**
 * @file JZ42 连续子数组的最大和
 * @brief 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    要求时间复杂度为O(n)。
 * 
    思路：
        1. 动态规划 maxSubArray
            - dp[i] 表示以 i 位置为结尾时，子数组和的最大值
            dp[i] = max(num[i], dp[i - 1] + nums[i])

        2. 贪心算法 maxSubArray1
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int m = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            
            m = max(dp[i], m);
        }

        return m;
    }

    int maxSubArray1(vector<int>& nums) {
        int greatestSum = 0x80000000;
        int currSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (currSum <= 0) {
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
            
            if (greatestSum < currSum) {
                greatestSum = currSum;
            } 
        }

        return greatestSum;
    }
};

int main() {
   Solution s;
   vector<int> arr {2, 3, -1, 2, -5, 4};
   int ret = s.maxSubArray(arr);
   std::cout << ret << std::endl;
}