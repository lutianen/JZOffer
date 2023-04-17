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

        return binSeach(nums, tar) - binSeach(nums, tar - 1);
    }

private:
    // 二分查找变形：找到目标连续区间的最左侧下标
    int binSeach(vector<int>& nums, int tar) {
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
};

int main() {
    Solution s;
    vector<int> nums{1, 5, 5, 7, 7, 8, 10};
    // vector<int> nums{1};
    std::cout << s.search(nums, 7) << std::endl;
}