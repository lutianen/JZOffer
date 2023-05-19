/**
 * @file LQ377 组合总和 IV
 * @brief 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
        请你从 nums 中找出并返回总和为 target 的元素组合的个数。
        题目数据保证答案符合 32 位整数范围。

    链接：https://leetcode.cn/problems/combination-sum-iv
 *  思路：
        1. backtrack: 超时
        2. 完全背包：先遍历背包，在遍历物品
            d[i] - 表示装满容量为 i 的背包的组合总数
            d[i] += d[i - num[j]]
 */

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 完全背包
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> d(target + 1);
        d[0] = 1;

        // 先背包在物品
        for (int i = 1; i <= target; ++i) {
            for (size_t j = 0; j < nums.size(); ++j) {
                if (nums[j] <= i && d[i - nums[j]] < INT_MAX - d[i]) {
                    d[i] += d[i - nums[j]];
                }
            }
        }

        return d[target];
    }

    // 超时
    int combinationSum4_bt(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> path;
        vector<vector<int>> ps;

        std::function<void()> dfs = [&]() {
            if (sum >= target) {
                if (sum == target) {
                    ps.push_back(path);
                    return;
                } else
                    return;
            }

            for (size_t i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                path.push_back(nums[i]);
                dfs();
                sum -= nums[i];
                path.pop_back();
            }
        };

        dfs();
        return ps.size();
    }
};

int main() {
    Solution so;
    vector<int> nums{4, 2, 1};
    int target = 32;
    std::cout << so.combinationSum4(nums, target) << std::endl;
    std::cout << so.combinationSum4_bt(nums, target) << std::endl;
}