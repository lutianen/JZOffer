/**
 * @file LQ55 跳跃游戏
 * @brief 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    判断你是否能够到达最后一个下标。
 * 思路：贪心算法
 */

#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;

        // cover 所能达到的最远地方
        int cover = nums[0];
        for(int i = 0; i <= cover; i++) {
            cover = max(cover, nums[i] + i);
            if (cover >= nums.size() - 1) 
                return true;
        } 

        return false;
    }
};