/**
 * @brief 缺失的第一个正数
 * @link https://leetcode.cn/problems/first-missing-positive/
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
public:
    // 哈希实现
    // 空间复杂度 O(N), 时间复杂度 O(N)
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> uset;
        for (const int num : nums) uset.insert(num);

        size_t i = 1;
        for (; i <= nums.size(); ++i)
            if (uset.find(i) == uset.end()) return i;

        return i;
    }

    // 原地哈希
    // 空间复杂度 O(1), 时间复杂度 O(N)
    int firstMissingPositive2(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) break;

                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }

        for (size_t i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1) return i + 1;

        return nums.size() + 1;
    }
};

int main() {
    Solution so;
    vector<int> nums{3, 4, -1, 1};
    std::cout << so.firstMissingPositive(nums) << std::endl;
    return 0;
}