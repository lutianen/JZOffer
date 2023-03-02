/**
 * @file LQ46 全排列
 * @brief 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
 * 思路：回溯算法
 */


#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();

        vector<bool> used(nums.size(), false);

        backTracking(nums, used);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backTracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (used[i] == true) continue;
            used[i] = true;

            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};