/**
 * @file LQ16 最接近的三数之和
 * @brief 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
        请你从 nums 中选出三个整数，使它们的和与 target 最接近。
        返回这三个数的和。
        假定每组输入只存在恰好一个解。

    链接：https://leetcode.cn/problems/3sum-closest

    思路：排序 + 双指针
        和三数之和思路相似
 */


#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int n = nums.size();
        int ret = 0;
        if (n < 3) {
            for (auto num : nums)
                ret += num;
            return ret;
        }

        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        ret = sum;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                sum  = nums[i] + nums[left] + nums[right];
            
                if (abs(sum - target) < abs(ret - target))
                    ret = sum;
                
                if (sum < target) 
                    left++;
                else if (sum > target)
                    right--;
                else 
                    return sum;
            }
        }

        return ret;
    }
};

int main() {
    Solution so;
    vector<int> nums{1, 1, 1, 0};
    cout << so.threeSumClosest(nums, -4);
}