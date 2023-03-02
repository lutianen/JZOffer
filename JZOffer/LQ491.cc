/**
 * @file LQ491 递增子序列
 * @brief 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
        数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

    链接：https://leetcode.cn/problems/non-decreasing-subsequences

    思路：回溯 + set 去重
 */

#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();

        backTracking(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res {};
    vector<int> path {};

    void backTracking(const vector<int>& nums, int idx) {        
        if (path.size() >= 2) {
            res.push_back(path);
        }

        // 使用set对本层元素进行去重
        unordered_set<int> uset;
        for (int i = idx; i < nums.size(); ++i) {
            if ((!path.empty() && nums[i] < path.back()) || 
                uset.find(nums[i]) != uset.end()) continue;

            // 记录这个元素在本层用过了，本层后面不能再用了
            uset.insert(nums[i]);

            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums {4, 4, 3, 2, 1};
    s.findSubsequences(nums);
}