/**
 * @file LQ494 目标和
 * @brief 给你一个整数数组 nums 和一个整数 target；
        向数组中的每个整数前添加'+'或'-'，然后串联起所有整数，可以构造一个表达式，
        返回运算结果等于 target 的不同 表达式 的数目
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto e : nums) sum += e;
        if (std::abs(target) > sum) return 0;
        sum += target;
        if (sum % 2 == 1) return 0;

        int p = sum / 2;
        int n = nums.size();
        vector<int> d(p + 1, 0);
        d[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = p; j >= nums[i]; --j) {
                d[j] += d[j - nums[i]];
            }
        }

        return d[p];
    }
};

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;

    Solution so;
    std::cout << so.findTargetSumWays(nums, target) << std::endl;

    return 0;
}