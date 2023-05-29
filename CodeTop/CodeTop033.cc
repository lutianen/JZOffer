/**
 * @brief 二分查找
 * @link https://leetcode.cn/problems/binary-search/
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = ((right - left) >> 1) + left;
            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                return middle;
        }

        return -1;
    }
};

int main() {
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int tar = 2;
    Solution so;
    std::cout << so.search(nums, tar) << std::endl;
    return 0;
}