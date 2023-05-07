/**
 * @file LQ213 打家劫舍 II
 * @brief
        你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
        这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
        同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
        给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，今晚能够偷窃到的最高金额。

    链接：https://leetcode.cn/problems/house-robber-ii

    思路：DP
        将环形数组人为分为两段，即手动选择第一间房子是否偷取？这使得环形数组退化为线性数组（打家劫舍）
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];

        // 两段线性区间取最大值
        return std::max(rob(nums, 0, nums.size() - 2),
                        rob(nums, 1, nums.size() - 1));
    }

private:
    // 线性区间 DP
    int rob(vector<int>& nums, int st, int ed) {
        if (st > ed) return 0;
        if (st == ed) return nums[st];

        int n = ed - st + 1;
        int a = nums[st];
        int b = std::max(nums[st], nums[st + 1]);
        for (int i = 2; i < n; ++i) {
            int temp = std::max(b, a + nums[st + i]);
            a = b;
            b = temp;
        }

        return b;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 1};
    Solution so;
    std::cout << so.rob(nums) << std::endl;
}