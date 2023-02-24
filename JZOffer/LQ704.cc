/**
 * @file LQ704 二分查找
 * @brief 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
    写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
    
    链接：https://leetcode.cn/problems/binary-search

    思路：二分查找
        前提：数据有序（升序或降序）
 */


#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        // 左右侧边界指针
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while (left <= right) {
            // 中间节点
            int middle = left + ((right - left) >> 1);

            // target 位于左侧区间
            if (target < nums[middle])  right = middle - 1;
            // target 位于右侧区间
            else if (target > nums[middle]) left = middle + 1;
            // 找到 target
            else {
                res = middle;
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums {-1,0,3,5,9,12};
    Solution s;
    int res = s.search(nums, 9);
    cout << res << endl;

    cout << s.search(nums, 4) << endl;

    return 0;
}