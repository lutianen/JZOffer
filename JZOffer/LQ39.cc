/**
 * @file LQ39 组合总和
 * @brief 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
    找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
    candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
    对于给定的输入，保证和为 target 的不同组合数少于 150 个。

    链接：https://leetcode.cn/problems/combination-sum
 * 

    思路：回溯算法 - for 循环横向遍历，递归纵向遍历，回溯不断调整结果集
        - 对于组合问题：什么时候需要 startIndex ?
            如果是一个集合来求组合的话，就需要 startIndex;
            如果是多个集合来求组合的话，各个集合之间相互不影响，就不需要 startIndex；
        - 对于排列问题：什么时候需要 startIndex ? 
            ...
 */


#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();

        backtracking(candidates, target, 0);
        return res;
    }

private:
    vector<vector<int>> res {};
    vector<int> path {};
    int sum = 0;

    void backtracking(vector<int>& nums, int tar, int startIdx) {
        if (sum > tar)
            return;
        if (sum == tar) {
            res.push_back(path);
            return;
        }

        for (int i = startIdx; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            sum += nums[i];

            backtracking(nums, tar, i);
            sum -= nums[i];
            path.pop_back();
        }
    }
};