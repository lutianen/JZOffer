/**
 * @file LQ136 只出现一次的数字
 * @brief 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其
        余每个元素均出现两次。找出那个只出现了一次的元素。
        你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

    链接：https://leetcode.cn/problems/single-number
 *  思路：异或的性质
 */

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return -1;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};