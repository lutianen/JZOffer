/**
 * @file LQ15 三数之和
 * @brief 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
    你返回所有和为 0 且不重复的三元组。
    注意：答案中不可以包含重复的三元组。

    链接：https://leetcode.cn/problems/3sum

    难点：答案去重

 *  思路：排序加双指针
 */


#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty() || nums.size() < 3)
            return {};

        vector<vector<int>> res;
        // 排序，从小到大
        std::sort(nums.begin(), nums.end());
        
        // 排完序后，如果第一个都大于 0，那么该数组所有数字大于 0，不存在
        if(nums[0] > 0) return res;

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            // 去重：当前元素值和前一个元素值相同时，跳过当前元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 左右指针
            int L = i + 1;
            int R = len - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    res.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    // 去重
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R] == nums[R - 1]) R--;
                    
                    // 添加后，两个指针同时移动
                    L++; R--;
                } else if (sum < 0) L++;
                else R--;
            }
        }
        
        return res;
    }
};