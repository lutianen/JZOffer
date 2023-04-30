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

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size(), sum = 0;
        if (n <= 3) {
            for (int i = 0; i < n; i++) sum += nums[i];
            return sum;
        }

        int ret = 0x3FFFFFFF;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ret - target)) ret = sum;

                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else {
                    ret = sum;
                    break;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution so;
    vector<int> nums{-1, 2, 1, -4};
    cout << so.threeSumClosest(nums, 1);
}