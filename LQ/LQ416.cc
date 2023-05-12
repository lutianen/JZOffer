/**
 * @file LQ416 分割等和子集
 * @brief  给你一个 只包含正整数 的 非空 数组 nums;
        请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *  思路： 动态规划 - 0-1背包
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<int> d(target + 1, 0);
        // 先遍历物品再遍历背包（倒序遍历）
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) 
                d[j] = std::max(d[j], d[j - nums[i]] + nums[i]);
        }

        return d[target] == target;
    }
};

int main() {
    // vector<int> nums{1,5,11,5};
    vector<int> nums{1,2,3,5};
    Solution so;
    std::cout << so.canPartition(nums) << std::endl;
    return 0;
}
 


