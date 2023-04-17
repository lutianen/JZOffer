/**
 * @file JZ53 在排序数组中查找数字 I
 * @brief 统计一个数字在排序数组中出现的次数

    思路：二分查找
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        if (nums.empty()) return 0;

        // return binSearch(nums, tar) - binSearch(nums, tar - 1);
        return binSearch2(nums, tar) - binSearch2(nums, tar - 1);
    }

private:
    // 二分查找变形：找到目标连续区间的最左侧下标
    //  时间复杂度 O(N)
    int binSearch(vector<int>& nums, int tar) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (tar < nums[m])
                r = m - 1;
            else if (tar > nums[m])
                l = m + 1;
            else {
                int j = m;
                while (j < nums.size() && nums[j] == tar) j++;
                return j - 1;
            }
        }

        return r;
    }

    // 时间复杂度 O(logn)
    int binSearch2(vector<int>& nums, int tar) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] <= tar)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 5, 5, 7, 7, 8, 10};
    // vector<int> nums{1};
    std::cout << s.search(nums, 1) << std::endl;
}