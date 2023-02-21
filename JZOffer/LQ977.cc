/**
 * @file LQ977 有序数组的平方
 * @brief 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
    要求：时间复杂度 O（n）
 * 
 */
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using std::vector;

class Solution {
public:

    /**
     * @brief 思路：利用对撞双指针
     *  利用数组的有序性，头尾双指针的元素的平方比较大小，较大者倒序入组；重复比较直至两指针相撞
     * @param nums 
     * @return vector<int> 
     */
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int l = 0, r = nums.size() - 1;
        int index = nums.size() - 1;
        while (l <= r) {
            if (std::pow(nums[l], 2) <= std::pow(nums[r], 2))
                res[index--] = std::pow(nums[r--], 2);
            else res[index--] = std::pow(nums[l++], 2);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums {-4,-1,0,3,10};
    vector<int> res = s.sortedSquares(nums);
    for (auto e : res) 
        std::cout << e << " " ;
}