/**
 * @file JZ57 和为s的两个数字
 * @brief 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
    如果有多对数字的和等于s，则输出任意一对即可。
 * 
 * 思路：利用双指针（left、right 起始位置分别指向 nums 的首尾元素），再根据该数组具有升序的特性，
        当两指针所指元素之和小于 target 时，left++；否则，right--，直至相等或两指针重合
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty()) return {};

        int left = 0, right = nums.size() - 1;
        vector<int> res;
        while (left < right) {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{2, 7, 11, 15};
    int s = 9;
    Solution so;
    vector<int> ret = so.twoSum(nums, s);
    for (const auto& num : ret) cout << num << " ";
    cout << endl;
    return 0;
}