/**
 * @file LQ416 分割等和子集
 * @brief 给你一个 只包含正整数 的 非空 数组 nums
 * 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

    思路：0 - 1 背包，动态规划，典型的选与不选
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;

        int sum = 0, tar = 0;
        for (auto n : nums) sum += n;
        if ((sum & 1) == 1)
            return false;
        else
            tar = sum / 2;

        // 开始 0 - 1 背包：先遍历物品，再遍历背包（且逆序）
        // d[i] = max(d[i], d[i - nums[j]] + nums[j])
        int n = nums.size();
        vector<int> d(sum + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = tar; j >= nums[i]; j--) {
                d[j] = max(d[j], d[j - nums[i]] + nums[i]);
            }
        }

        return d[tar] == tar;
    }
};