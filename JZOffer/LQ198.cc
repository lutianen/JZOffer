/**
 * @file LQ198 打家劫舍
 * @brief 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
        给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

    链接：https://leetcode.cn/problems/house-robber
 *  思路：动态规划
        - dp[i]，表示以 i 结尾时，所能获得的最大金额
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
 */

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];

        vector<int> d(nums.size());
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            d[i] = max(d[i - 2] + nums[i], d[i - 1]);
        }

        return d[nums.size() - 1];
    }
};