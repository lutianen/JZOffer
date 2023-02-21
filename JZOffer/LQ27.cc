/**
 * @file LQ27 移除元素
 * @brief 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

    链接：https://leetcode.cn/problems/remove-element
 */


#include <vector>

using std::vector;


class Solution {
public:
    /**
    * @brief 思路：利用快慢双指针
        当快指针所指元素不为待删除元素时，就进行数值覆盖；
        否则不覆盖，快指针移动，慢指针不动
    * 时间复杂度：O（n）
    * @param nums 
    * @param val 
    * @return int 
    */
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) 
            if (nums[fast] != val) 
                nums[slow++] = nums[fast];
        return slow;
    }

   
};

