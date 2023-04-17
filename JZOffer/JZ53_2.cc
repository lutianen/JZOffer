/**
 * @file JZ53 II 0～n-1中缺失的数字
 * @brief
 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
    在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

    思路：
        1. 保证数组不为空，且首元素为0，然后利用相邻两元素之间差值为1，找到缺失的数字
        2. 二分法
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // 迭代法
    // 时间复杂度 O(n)
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return -1;

        int pre = nums[0];
        if (pre != 0) return 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - pre != 1)
                break;
            else
                pre = nums[i];
        }

        return pre + 1;
    }


    // 二分法
    // 时间复杂度 O(logn)
    int missingNumber2(vector<int>& nums) {
        if (nums.empty()) return -1;

        int L = 0, R = nums.size() - 1;

        while (L <= R) {
            int M = ((R - L) >> 1) + L;
            if (nums[M] > M)
                R = M - 1;
            else
                L = M + 1;
        }

        return L;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5};
    std::cout << s.missingNumber2(nums) << std::endl;
}
