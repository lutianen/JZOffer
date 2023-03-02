/**
 * @file LQ90 子集 II
 * @brief 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
        解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

    链接：https://leetcode.cn/problems/subsets-ii
 * 思路：排序 + 回溯
    排序去重：if (i > idx && nums[i - 1] == nums[i]) continue;
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();

        sort(nums.begin(), nums.end());

        backTracking(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backTracking(vector<int>& nums, int idx) {
        res.push_back(path);
        if (idx >= nums.size()) return;

        for (int i = idx; i < nums.size(); ++i) {
            // 去重 i > idx
            if (i > idx && nums[i - 1] == nums[i]) continue;
           
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }};