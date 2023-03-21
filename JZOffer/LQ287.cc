/**
 * @file LQ287 寻找重复数
 * @brief 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
        假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
        你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
    链接：https://leetcode.cn/problems/find-the-duplicate-number
 *  思路：判断链表是否存在环 【快慢指针】
        将数组看作成链表 - 前提数组中的范围是 [1, n]；
        nums[1, 3, 4, 2, 2]
        映射关系：n -> f(n)  <=> n -> nums[n]
        0 -> 1
        1 -> 3
        2 -> 4  *
        3 -> 2
        4 -> 2  *
        理论上讲，若存在相同的数，则必然存在多对一的映射，链表一定存在环路。
 */


#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       if (nums.size() < 2) return -1;

        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};