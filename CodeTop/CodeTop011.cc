/**
 * @brief 搜索旋转排序数组
 * @link https://leetcode.cn/problems/search-in-rotated-sorted-array
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            // 恰好找到，直接返回
            if (nums[mid] == target) return mid;

            // 区间划分
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return nums[left] == target ? left : -1;
    }
};

int main() {
    // vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    vector<int> nums{1, 2};
    Solution so;
    int tar = 1;
    cout << so.search(nums, tar) << endl;
    return 0;
}